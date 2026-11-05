# Kayıplı boost faktörü: JCAP21 Şekil 15–19 karşılaştırması

Sonuç: kapalı form β(ω) (denk. 4.31 + 4.45) makaledeki dört şekli de birkaç yüzde içinde
yeniden üretiyor. Şekil 19 ancak iki ek varsayımla tutuyor (aşağıda). Benchmark: Material 2,
B = 2 T, n = 5, m_Θ = 1.8 meV, f_Θ = 70 eV.

## Sayısal karşılaştırma

Makale değerleri şekillerden gözle okunmuştur (±%3 civarı okuma hatası).

| Şekil | Durum | Makale | Bu kod |
| --- | --- | --- | --- |
| 15 | d = 2 mm, kayıpsız, tepe β | ≈ 67 | 68.6 |
| 15 | d = 5 mm, kayıpsız, tepe β | ≈ 420 | 429 |
| 15 | d = 10 mm, kayıpsız, tepe β | ≈ 1680 | 1718 |
| 17 | d = 1 mm, kayıpsız | ≈ 17.5 | 17.1 |
| 17 | Γ_m = 10⁻⁴ / 10⁻³ / 10⁻² meV | 16 / 8.5 / 1.8 | 15.4 / 8.1 / 1.8 |
| 17 | Γ_ρ = 10⁻⁴ / 10⁻³ / 10⁻² meV | 16.7 / 11.3 / 2.6 | 16.2 / 10.9 / 2.8 |
| 18 | d = 5 mm, Γ_m = 10⁻⁴: ω₀ / ω₁ | 31 / 19.5 | 31.0 / 19.0 |
| 18 | d = 5 mm, Γ_ρ = 10⁻⁴: ω₀ / ω₁ | 56 / 27 | 55.4 / 26.7 |
| 18 | d = 5 mm, kayıpsız ω₁ | ≈ 46 | 46.8 |
| 19 | log₁₀β_max, Γ = 10⁻⁵, n = 3 / 7 | 2.45 / 1.95 | 2.45 / 1.96 |
| 19 | log₁₀β_max, Γ = 10⁻⁴, n = 3 / 7 | 1.78 / 1.30 | 1.78 / 1.29 |
| 19 | log₁₀β_max, Γ = 10⁻³, n = 3 / 7 | 1.10 / 0.62 | 1.12 / 0.62 |

Ek kontroller (testlerde):

- Denk. 4.33 (analitik ω_j) tam çözümle 10⁻⁵ içinde aynı.
- Kayıpsız tepe ∝ d² (denk. 4.43).
- Denk. 4.51'deki d_opt sayısal optimumla %10 içinde aynı (6.1, 2.8, 1.3 mm; n = 5).
- β² genişliği = κ_rad + Γ_m + (b/ω_LO)² Γ_ρ (denk. 4.49'un benim okumam) %3 içinde doğru.
  Yani iç kayıp, foton kaybının foton kesri b²/ω_LO² ile ağırlıklandırılmış hali.

## Makaleyle ilgili bulgular

1. **b'nin değeri.** Denk. 2.3 b = 1.6 meV (2 T) yazıyor. Aynı formül Heaviside–Lorentz
   birimlerinde 1.834 meV veriyor (ω_LO = 2.5694 meV). Şekil 17 ve 18'deki ω_LO çizgisi
   ≈ 2.5697 meV'de, yani şekiller 1.83 meV ile çizilmiş; 1.6 meV metindeki bir yazım/hesap
   hatası gibi duruyor. Şekil 15 ise biraz farklı: ω_LO ≈ 2.5606 meV (b ≈ 1.82 meV),
   %0.7 daha düşük. Bu yüzden Şekil 15'te x eksenini kendi ω_LO'muza göre kaydırdık;
   tepe değerleri %2 içinde.
2. **Şekil 19'da n değişirken b sabit.** b ∝ 1/√ε olduğu hâlde, şekil n = 3…7 aralığında
   b'yi n = 5 değerinde tutarak çizilmiş. b'yi n ile birlikte değiştirince bant çok daha
   geniş çıkıyor (ör. Γ = 10⁻⁴'te 1.94 / 1.17), makaleyle tutmuyor.
3. **Şekil 19 Lorentz yaklaşımıyla çizilmiş.** Makale tepe β'yı A_j/(γ_j ω_j) (denk. 4.50)
   ile çizmiş; bu d ≫ d_opt için 1/d gibi sıfıra iniyor. Tam denk. 4.31 ise kalın kayıplı
   katmanda sabit bir değere oturuyor: katman yarı-sonsuz bir ortam gibi yalnız ön
   yüzeyinden ışıyor. d_opt civarında ikisi aynı, yani duyarlılık tahminlerini etkilemez;
   ama kalın numuneler için makalenin eğrisi kötümser.

Şekiller: `figures/fig15_reproduction.png` … `fig19_reproduction.png`
(Şekil 19 sol panel = makalenin yöntemi, sağ panel = tam formül).
