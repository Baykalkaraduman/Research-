"""Boost factor of a single lossy TMI layer in vacuum (JCAP21 Sec. 4.2.3).

All energies in meV, thickness d in 1/meV (use units.mm_to_inv_meV).
"""
import numpy as np
from scipy.optimize import brentq, minimize_scalar


def n_theta_sq(omega, mat, B_T):
    """Effective refractive index squared with losses, eq. 4.45."""
    omega = np.asarray(omega, dtype=complex)
    b2 = mat.b(B_T) ** 2
    return mat.n ** 2 * (1 + b2 / (mat.m_theta ** 2 - omega ** 2 - 1j * omega * mat.gamma_m)
                         + 1j * mat.gamma_rho / omega)


def boost_amplitude(omega, d, mat, B_T):
    """Complex emitted field E_2^{++}/E_0, eq. 4.31 (first order in g_agamma).

    Even in n_theta, so the square-root branch does not matter.
    """
    nt = np.sqrt(n_theta_sq(omega, mat, B_T))
    half = 0.5 * np.asarray(omega) * nt * d          # Delta/2, Delta = omega n_theta d
    s, c = np.sin(half), np.cos(half)
    return -s * (1 - nt ** 2) / (nt * (nt * s + 1j * c))


def boost(omega, d, mat, B_T):
    """Boost factor beta = |E_2^{++}/E_0| (eq. 4.42, unsquared)."""
    return np.abs(boost_amplitude(omega, d, mat, B_T))


def resonance_lossless(j, d, mat, B_T):
    """Lossless resonance omega_j: n_theta(omega) omega d = (2j+1) pi, eq. 4.32."""
    wlo = mat.omega_LO(B_T)
    lossless = mat.with_(gamma_m=0.0, gamma_rho=0.0)
    target = (2 * j + 1) * np.pi

    def f(w):
        return np.sqrt(n_theta_sq(w, lossless, B_T).real) * w * d - target

    lo, hi = wlo * (1 + 1e-14), wlo * 1.01
    while f(hi) < 0:
        hi = wlo + 2 * (hi - wlo)
    return brentq(f, lo, hi, xtol=1e-16, rtol=1e-15)


def resonance_approx(j, d, mat, B_T):
    """Analytic omega_j, eq. 4.33 (leading order)."""
    wlo, b = mat.omega_LO(B_T), mat.b(B_T)
    Dj = (2 * j + 1) * np.pi
    return np.sqrt(wlo ** 2 + Dj ** 2 * b ** 2 / (mat.n ** 2 * d ** 2 * wlo ** 2))


def peak_boost(d, mat, B_T, j=0):
    """Maximum of beta near resonance j (location, value), with losses."""
    wj = resonance_lossless(j, d, mat, B_T)
    wlo = mat.omega_LO(B_T)
    if j == 0:
        lo = wlo
        hi = wj + 3 * (wj - wlo)
    else:  # window between the neighbouring resonances
        lo = 0.5 * (resonance_lossless(j - 1, d, mat, B_T) + wj)
        hi = 0.5 * (wj + resonance_lossless(j + 1, d, mat, B_T))
    grid = np.linspace(lo, hi, 4001)
    vals = boost(grid, d, mat, B_T)
    k = int(np.argmax(vals))
    a, c = grid[max(k - 1, 0)], grid[min(k + 1, len(grid) - 1)]
    res = minimize_scalar(lambda w: -boost(w, d, mat, B_T), bounds=(a, c),
                          method="bounded", options={"xatol": 1e-14 * wj})
    return res.x, -res.fun


def width_analytic(j, d, mat, B_T):
    """FWHM of beta^2, eq. 4.49: radiative + loss part (my reading of the parentheses)."""
    wlo, b = mat.omega_LO(B_T), mat.b(B_T)
    Dj = (2 * j + 1) * np.pi
    k_rad = 4 * b ** 2 * Dj ** 2 / (mat.n ** 2 * wlo ** 4 * d ** 3)
    k_int = mat.gamma_m + (b ** 2 / wlo ** 2) * mat.gamma_rho
    return k_rad, k_int


def d_opt(mat, B_T, j=0):
    """Optimal thickness, eq. 4.51 (as printed; checked numerically in tests)."""
    wlo, b = mat.omega_LO(B_T), mat.b(B_T)
    Dj = (2 * j + 1) * np.pi
    loss = mat.gamma_rho / wlo + mat.gamma_m * wlo / b ** 2
    return (2 / wlo) * (Dj / mat.n) ** (2 / 3) * loss ** (-1 / 3)


def peak_boost_lorentzian(d, mat, B_T, j=0):
    """Peak beta from the Lorentzian approximation, beta = A_j / (gamma_j omega_j).

    Eqs. 4.40, 4.49, 4.50 with omega_j ~ omega_LO. JCAP21 Fig. 19 is drawn with this
    approximation; it falls off as 1/d for d >> d_opt, whereas the exact eq. 4.31
    saturates (a thick lossy slab still radiates from its front face).
    """
    wlo, b = mat.omega_LO(B_T), mat.b(B_T)
    A = 4 * b ** 2 / (mat.n ** 2 * wlo * d)
    k_rad, k_int = width_analytic(j, d, mat, B_T)
    return A / ((k_rad + k_int) * wlo)
