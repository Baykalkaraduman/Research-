"""Natural units (hbar = c = 1, Heaviside-Lorentz), energies in meV."""
import math

HBARC_MEV_M = 1.973269804e-4      # hbar*c in meV*m (CODATA 2018)
TESLA_EV2 = 195.3535              # 1 T in eV^2 (Heaviside-Lorentz, e = sqrt(4 pi alpha))
TESLA_MEV2 = TESLA_EV2 * 1e6      # 1 T in meV^2
ALPHA = 1 / 137.035999084         # fine-structure constant (CODATA 2018)


def mm_to_inv_meV(d_mm):
    """Length in mm -> 1/meV."""
    return d_mm * 1e-3 / HBARC_MEV_M


def meV_to_THz(E_meV):
    """Photon energy in meV -> frequency in THz (f = E / h)."""
    return E_meV / 4.135667696
