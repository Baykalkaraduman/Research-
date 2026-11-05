"""Benchmark parameters, each with its source in JCAP21."""
from dataclasses import dataclass, replace
import math

from .units import ALPHA, TESLA_MEV2


@dataclass(frozen=True)
class Material:
    m_theta: float = 1.8      # AQ mass [meV]; Table 5 / Table 8 ("Material 2")
    f_theta: float = 70e3     # AQ decay constant [meV] (= 70 eV); Table 5 / Table 8
    eps: float = 25.0         # permittivity eps_1; Table 4 / Table 8 (n = 5)
    mu: float = 1.0           # permeability; Table 8
    gamma_m: float = 0.0      # magnon (AQ) loss Gamma_m [meV]; Table 6 / Table 8
    gamma_rho: float = 0.0    # photon loss Gamma_rho = sigma/eps [meV]; eq. 3.29, Table 8
    b_override: float | None = None  # fix b [meV] at given B instead of eq. 2.3 (for figure checks)

    @property
    def n(self):
        return math.sqrt(self.eps * self.mu)

    def b(self, B_T):
        """Mixing scale b [meV], eq. 2.3: b = alpha B / (pi sqrt(2) sqrt(eps) f_theta).

        Evaluated in Heaviside-Lorentz units. NOTE: eq. 2.3 prints b = 1.6 meV at
        2 T, while this evaluates to 1.83 meV; JCAP21 Figs. 17-18 (omega_LO = 2.5694 meV)
        are consistent with 1.83 meV. See docs/boost_factor.md.
        """
        if self.b_override is not None:
            return self.b_override
        return ALPHA * B_T * TESLA_MEV2 / (math.pi * math.sqrt(2 * self.eps) * self.f_theta)

    def omega_LO(self, B_T):
        """Upper edge of the polariton gap, eq. 3.33."""
        return math.hypot(self.m_theta, self.b(B_T))

    def with_(self, **kw):
        return replace(self, **kw)


MATERIAL_2 = Material()   # benchmark, Mn2Bi2Te5-inspired (Table 8)
B_BENCH_T = 2.0           # benchmark field [T], Table 8
