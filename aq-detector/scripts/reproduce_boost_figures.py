"""Reproduce JCAP21 Figs. 15, 17, 18, 19 (boost factor of one TMI layer).

Usage: python scripts/reproduce_boost_figures.py [outdir]
"""
import sys
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from aqdet.boost import boost, peak_boost, peak_boost_lorentzian, resonance_lossless  # noqa: E402
from aqdet.params import B_BENCH_T, MATERIAL_2  # noqa: E402
from aqdet.units import mm_to_inv_meV  # noqa: E402

OUT = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(__file__).resolve().parents[1] / "figures"
OUT.mkdir(parents=True, exist_ok=True)
B = B_BENCH_T
M = MATERIAL_2
WLO = M.omega_LO(B)

# Ordinal loss ramp: lossless = neutral ink, then one blue hue light -> dark.
INK = "#2b2b2b"
LOSS_COLORS = {0: INK, 1e-5: "#86b6ef", 1e-4: "#3987e5", 1e-3: "#1c5cab", 1e-2: "#0d366b"}
plt.rcParams.update({
    "font.size": 9, "axes.edgecolor": "#888", "axes.linewidth": 0.6,
    "xtick.color": "#555", "ytick.color": "#555", "axes.labelcolor": INK,
    "axes.grid": True, "grid.color": "#e6e6e6", "grid.linewidth": 0.5,
    "lines.linewidth": 1.6, "figure.dpi": 150,
})


def vline(ax, x, x0, label, ls, span=None):
    if span is not None and not (0 <= x - x0 <= span):
        return
    ax.axvline(x - x0, color="#777", lw=0.8, ls=ls)
    ax.annotate(label, (x - x0, 0.97), xycoords=("data", "axes fraction"),
                ha="left", va="top", fontsize=8, color="#555", xytext=(2, 0),
                textcoords="offset points")


def fig15():
    """Lossless beta vs m_a for d = 0.2, 2, 5, 10 mm (paper's x-offsets kept)."""
    # (d [mm], window span [meV], anchor, anchor position in window) chosen to match
    # the paper's panels; offsets are taken from OUR omega_LO / omega_0, since the
    # paper's Fig. 15 uses a slightly lower omega_LO (see docs/boost_factor.md).
    panels = [(0.2, 0.2, "LO", 0.058), (2, 5e-3, "LO", 6e-4), (5, 1e-4, "w0", 4.3e-5), (10, 1e-5, "w0", 6e-6)]
    fig, axs = plt.subplots(2, 2, figsize=(7.5, 5.2))
    for ax, (dmm, span, anchor, pos) in zip(axs.flat, panels):
        d = mm_to_inv_meV(dmm)
        w0 = resonance_lossless(0, d, M, B)
        lo = (WLO if anchor == "LO" else w0) - pos
        x = np.linspace(0, span, 6001)
        w = lo + x
        ax.plot(x, boost(w, d, M, B), color=INK)
        vline(ax, WLO, lo, r"$\omega_{LO}$", "-", span)
        vline(ax, w0, lo, r"$\omega_0$", "--", span)
        if dmm == 2:
            vline(ax, resonance_lossless(1, d, M, B), lo, r"$\omega_1$", "--")
        ax.set_title(f"d = {dmm:g} mm", fontsize=9, loc="left")
        ax.set_xlabel(rf"$m_a$ [meV] $-$ {lo:.6g}")
        ax.set_ylabel(r"$\beta$")
        ax.ticklabel_format(axis="x", style="sci", scilimits=(-2, 2))
    fig.suptitle("Fig. 15 reproduction: lossless boost factor, Material 2, B = 2 T", fontsize=10)
    fig.tight_layout()
    fig.savefig(OUT / "fig15_reproduction.png")


def loss_panels(dmm, lo_from_LO, span, fname, title, js):
    """Window starts lo_from_LO below OUR omega_LO, matching the paper's panel layout."""
    d = mm_to_inv_meV(dmm)
    x0 = WLO - lo_from_LO
    fig, axs = plt.subplots(1, 2, figsize=(7.5, 3.2), sharey=True)
    x = np.linspace(0, span, 6001)
    for ax, key, lab in zip(axs, ["gamma_m", "gamma_rho"], [r"$\Gamma_m$", r"$\Gamma_\rho$"]):
        for G, col in LOSS_COLORS.items():
            m = M.with_(**{key: G})
            ax.plot(x, boost(x0 + x, d, m, B), color=col,
                    label="0" if G == 0 else f"{G:.0e}")
        vline(ax, WLO, x0, r"$\omega_{LO}$", "-")
        for j in js:
            vline(ax, resonance_lossless(j, d, M, B), x0, rf"$\omega_{j}$", "--")
        ax.set_title(f"{lab} varied [meV], d = {dmm:g} mm", fontsize=9, loc="left")
        ax.set_xlabel(rf"$m_a$ [meV] $-$ {x0:.6g}")
        ax.ticklabel_format(axis="x", style="sci", scilimits=(-2, 2))
    axs[0].set_ylabel(r"$\beta$")
    axs[1].legend(title="loss [meV]", fontsize=7, title_fontsize=7, frameon=False)
    if dmm == 5:
        axs[0].set_ylim(0, 80)
    fig.suptitle(title, fontsize=10)
    fig.tight_layout()
    fig.savefig(OUT / fname)


def fig19():
    """Peak beta at omega_0 vs d; bands n = 3..7 with b held at its n = 5 value.

    Left: Lorentzian approximation (what the paper plots). Right: exact eq. 4.31.
    """
    b5 = M.b(B)
    ds = np.linspace(0.15, 10, 198)
    fig, axs = plt.subplots(1, 2, figsize=(8.6, 3.4), sharey=True)
    for ax, exact in zip(axs, [False, True]):
        def peak(x, m):
            d = mm_to_inv_meV(x)
            return peak_boost(d, m, B)[1] if exact else peak_boost_lorentzian(d, m, B)
        ax.plot(ds, np.log10([peak(x, M) for x in ds]), color=INK, label="0")
        for G in [1e-5, 1e-4, 1e-3]:
            curves = {}
            for n in (3, 7):
                m = M.with_(eps=n ** 2, gamma_m=G, gamma_rho=G, b_override=b5)
                curves[n] = np.log10([peak(x, m) for x in ds])
            col = LOSS_COLORS[G]
            ax.fill_between(ds, curves[7], curves[3], color=col, alpha=0.25, lw=0)
            ax.plot(ds, curves[3], color=col, lw=1.2, label=f"{G:.0e}")
            ax.plot(ds, curves[7], color=col, lw=1.2)
        ax.set_ylim(0, 3.3)
        ax.set_xlabel("d [mm]")
        ax.set_title("Lorentzian approx. (= paper)" if not exact else "Exact eq. 4.31",
                     fontsize=9, loc="left")
    axs[0].set_ylabel(r"$\log_{10}\beta_{\max}$")
    axs[1].legend(title=r"$\Gamma_\rho=\Gamma_m$ [meV]", fontsize=7, title_fontsize=7,
                  frameon=False, loc="center left", bbox_to_anchor=(1, 0.5))
    fig.suptitle("Fig. 19 reproduction: bands n = 3 (upper) to 7 (lower), b fixed at n = 5 value",
                 fontsize=10)
    fig.tight_layout()
    fig.savefig(OUT / "fig19_reproduction.png")


if __name__ == "__main__":
    fig15()
    loss_panels(1, 7e-4, 4e-3, "fig17_reproduction.png",
                "Fig. 17 reproduction: effect of losses, d = 1 mm", [0])
    loss_panels(5, 8e-5, 1e-3, "fig18_reproduction.png",
                "Fig. 18 reproduction: losses on higher resonances, d = 5 mm", [0, 1])
    fig19()
    print("written to", OUT)
