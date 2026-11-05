# AQ Detector

TOORAD tipi axion-kuasiparçacık (AQ) haloskobunun hesaplamalı modeli. Amaç, PT-simetrik
yükselteçli bir okumanın tarama hızı ve SNR'ını EP'siz referansa karşı hesaplamak.

Ana kaynak: Schütte-Engel ve ark., JCAP 08 (2021) 066, arXiv:2102.05366 (kodda "JCAP21").

## Durum

| Adım | İçerik | Durum |
| --- | --- | --- |
| V1–V3 | Kayıplı boost faktörü β(ω), Şekil 15, 17, 18, 19 | Tamam, bkz. [docs/boost_factor.md](docs/boost_factor.md) |
| V4 | Tek-mod indirgeme (κ_rad, κ_int) | Genişlik kontrolü yapıldı; tam uydurma sırada |
| V5–V7 | Duyarlılık (SPD, kuantum sınırlı lineer okuma), tarama | Sırada |

## Kullanım

```bash
pip install -r requirements.txt
python -m pytest tests            # yayımlanan şekillere karşı testler
python scripts/reproduce_boost_figures.py   # figures/ altına PNG yazar
```

## Yapı

- `aqdet/units.py`: doğal birimler (ħ = c = 1, Heaviside–Lorentz), enerji meV.
- `aqdet/params.py`: benchmark "Material 2" parametreleri, her biri kaynağıyla.
- `aqdet/boost.py`: n_Θ(ω) (denk. 4.45), β(ω) (denk. 4.31), rezonanslar, genişlik, d_opt.
- `scripts/reproduce_boost_figures.py`: Şekil 15, 17, 18, 19'un yeniden üretimi.
- `tests/`: makaledeki sayılara karşı doğrulama testleri.
