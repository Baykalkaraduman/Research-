"""V1-V3 (and part of V4) from the phase-1 plan: reproduce JCAP21 Figs. 15, 17, 18, 19.

Paper values are read off the published figures by eye, so tolerances are a few %.
"""
import numpy as np
import pytest

from aqdet.boost import (boost, d_opt, peak_boost, peak_boost_lorentzian,
                         resonance_approx, resonance_lossless, width_analytic)
from aqdet.params import MATERIAL_2 as M
from aqdet.units import mm_to_inv_meV as mm

B = 2.0


def test_omega_LO_benchmark():
    # eq. 3.33 with eq. 2.3 in HL units; paper Figs. 17/18 show omega_LO ~ 2.5697 meV
    assert M.omega_LO(B) == pytest.approx(2.5697, abs=5e-4)


@pytest.mark.parametrize("dmm, paper_peak", [(2, 67), (5, 420), (10, 1680)])
def test_fig15_lossless_peaks(dmm, paper_peak):
    assert peak_boost(mm(dmm), M, B)[1] == pytest.approx(paper_peak, rel=0.05)


@pytest.mark.parametrize("dmm", [1, 2, 5, 10])
def test_resonance_eq433_matches_exact(dmm):
    d = mm(dmm)
    assert resonance_approx(0, d, M, B) == pytest.approx(resonance_lossless(0, d, M, B), rel=1e-5)


def test_peak_scaling_lossless():
    # eq. 4.43: peak ~ d^2 in the lossless limit
    r = peak_boost(mm(10), M, B)[1] / peak_boost(mm(5), M, B)[1]
    assert r == pytest.approx(4, rel=0.02)


@pytest.mark.parametrize("key, G, paper", [
    ("gamma_m", 1e-4, 16.0), ("gamma_m", 1e-3, 8.5), ("gamma_m", 1e-2, 1.8),
    ("gamma_rho", 1e-4, 16.7), ("gamma_rho", 1e-3, 11.3), ("gamma_rho", 1e-2, 2.6),
])
def test_fig17_lossy_peaks(key, G, paper):
    assert peak_boost(mm(1), M.with_(**{key: G}), B)[1] == pytest.approx(paper, rel=0.1)


@pytest.mark.parametrize("key, j, paper", [
    ("gamma_m", 0, 31), ("gamma_rho", 0, 56), ("gamma_m", 1, 19.5), ("gamma_rho", 1, 27),
])
def test_fig18_higher_resonance(key, j, paper):
    assert peak_boost(mm(5), M.with_(**{key: 1e-4}), B, j)[1] == pytest.approx(paper, rel=0.07)


@pytest.mark.parametrize("G, n, paper_log10_max", [
    (1e-5, 3, 2.45), (1e-5, 7, 1.95), (1e-4, 3, 1.78), (1e-4, 7, 1.30), (1e-3, 3, 1.10), (1e-3, 7, 0.62),
])
def test_fig19_band_maxima_with_b_fixed(G, n, paper_log10_max):
    m = M.with_(eps=n ** 2, gamma_m=G, gamma_rho=G, b_override=M.b(B))
    ds = np.linspace(0.2, 10, 99)
    best = max(peak_boost_lorentzian(mm(x), m, B) for x in ds)
    assert np.log10(best) == pytest.approx(paper_log10_max, abs=0.05)


@pytest.mark.parametrize("G", [1e-5, 1e-4, 1e-3])
def test_d_opt_eq451_matches_numerical_optimum(G):
    m = M.with_(gamma_m=G, gamma_rho=G)
    ds = np.linspace(0.2, 10, 197)
    vals = [peak_boost(mm(x), m, B)[1] for x in ds]
    assert ds[int(np.argmax(vals))] == pytest.approx(d_opt(m, B) / mm(1), rel=0.1)


@pytest.mark.parametrize("key", ["gamma_m", "gamma_rho"])
def test_width_eq449_kappa_int_reading(key):
    # V4 (partial): FWHM of beta^2 = kappa_rad + Gamma_m + (b/omega_LO)^2 Gamma_rho
    d = mm(5)
    m = M.with_(**{key: 1e-5})
    wp, bp = peak_boost(d, m, B)
    g = np.linspace(wp - 1e-4, wp + 1e-4, 200001)
    above = g[boost(g, d, m, B) ** 2 >= bp ** 2 / 2]
    k_rad, k_int = width_analytic(0, d, m, B)
    assert above.max() - above.min() == pytest.approx(k_rad + k_int, rel=0.03)
