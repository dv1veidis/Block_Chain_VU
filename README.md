# Block_Chain_VU
VU Block Chain technologiju laboratorinis darbas

# Version 0.01

  1. Implementuota pradinė vartotojo įvestis

# Version 0.02

  1. Implementuotas pradinis hashavimo būdas

# Version 0.03

  1. Implementuotas atnaujintas hashavimo būdas
  2. Keleta bug fix

# Version 0.04

  1. Implementuota testavimo funkcija
  2. Kelete bug fix

# Version 0.05

  1. Implementuotas konstitucija.txt failo eilučių hashavimo greičio spartos matavimas
  2. Idėtas SHA-256 algoritmas palyginimui su mano sukurtu hash funkcijos algoritmu

# Version 0.1

  1. Implementuotas porų generavimo algoritmas
  2. Implementuotas bitu ir hexu lygmens skirtumo patikrinimas

# Testavimas

  ## Vieno simbolio failų hash skirtumas

  ``` powershell
  Hash skirtingas
  a ec5e9507ece9a1a5771475c36a2889e80fc4f7e91508d988c541169e8867d9b4
  b c8e3a1665a2271c8a91109aa50e9d1836fe7e3cb16409889c41b77424bf5fe2c
  ```

  ## Tuščio failo hashavimas

  ``` powershell
  Tuscias failas empty.txt : ca87eff938b9b5bef000000000000000008bdfc0ac35140ff739cddddddddddd
  ```

  ## Dviejų virš 1000 simbolių hashavimas

  ``` powershell
  Hash skirtingas
  TestA - a4eee54c9aa0668acb983fed39de47295beb40c2c074e7494bce763d99142506
  TestB - 38d3a6a7983af5641abc52adacdcd6beec5caa3e270a0d1094304875c0594b14
  ```

  ## Dviejų virš 1000 simbolių hashavimas, kai skiriasi tik 1 raidė

  ``` powershell
  Hash skirtingas
  TestA_A - fd3eecafa8300c47ae919c3996f4a4fc89e20d005d2b7662afbf68c27de96e96
  TestA_B - d798b24978ae14db83fe1457dd697ca024ae3af0ef49e7e346344c6a83194a7e
  ```

  ## Konstitucija.txt failo spartos matavimai su mano hash algoritmu ir su SHA-256
  ## Tyrimas atliktas su AMD RYZEN 4500u tyrimo vidurkis yra surinktas per 5000 hashavimo kartojimų

  ### Pavyzdys
  ```
  Average time for my hash = 0.221 ms
  Average time for my SHA-256 = 0.433 ms
  ```

  ## Porų kolizijos rezultai 100000 porų
  ```
  Ar norite generuoti naujas poras?(t/T - taip, n/N - ne)
  t
  Kolizija neaptikta
  ```

  ## Porų tesiskiriančių vienu simbolių hashavimo skirtumo rezultatai
  ```
  Kolizija neaptikta
                                 Hex  Bit
  Minimalio skirtingumo reiksmes: 50  118
  Maksimalios skirtingumo reiksmes: 64  214
  Hexadecimal difference achieved: 93.27 %
  Bit difference achieved: 32.55 %
  ```

# Išvada

  1. Maišos algoritmas atitinka visus reikalavimus. Tai matome iš skirtingų bandymų atliktų aukščiau.
  2. Maišos algoritmas garantuoja 64 simbolių išvesti.
  3. Maišos funkcija determininstinė tai reiškia, jog įvedus tą patį tekstą gaunamas ta pati maiša.
  4. Maišos funkcija atitinka lavinos efektą, kurį testavome pirmajame bandyme.
  5. Maišos funkcija efektyvi ir greičiu aplenkia testuotos SHA-256 funkcijos veikimo greitį.
  6. Maišos funkcija atspari kolizijai testuojant su 100000 porų. 
