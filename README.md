# v0.4 Tyrimai
## 1 Tyrimas:
* Laikui skaičiuoti naudoju chrono biblioteka ir Timer klasę.
* Naudoju -O3 vėliavėlę kompiliavimui.
### 1) Testuosiu 1 tūkstančio studentų failo sukūrimo ir uždarymo laiką.
* Kai yra 1 tūkstantis studentų, kiekvienas turi po 10 namų darbų ir vieną egzamino rezultatą.
* Pirmas bandymas:

![alt text](./images/image.png)
* 1 tūkst. studentų generavimo laiko testavimų lentelė

| 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|----------|----------|----------|----------|----------|----------|
| 0.0213 s | 0.0113 s | 0.0130 s | 0.0109 s | 0.0101 s | 0.0107  s|

### 2) Testuosiu 10 tūkstančių studentų failo sukūrimo ir uždarymo laiką.
* Kai yra 10 tūkstančių studentų, kiekvienas turi po 15 namų darbų ir vieną egzamino rezultatą.
* Pirmas bandymas:

![alt text](./images/image-2.png)
* 10 tūkst. studentų generavimo laiko testavimų lentelė

| 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|----------|----------|----------|----------|----------|----------|
| 0.0407 s | 0.0408 s | 0.0482 s | 0.0565 s | 0.0385 s | 0.0449 s |

### 3) Testuosiu 100 tūkstančių studentų failo sukūrimo ir uždarymo laiką.
* Kai yra 100 tūkstančių studentų, kiekvienas turi po 20 namų darbų ir vieną egzamino rezultatą.
* Pirmas bandymas:

![alt text](./images/image-3.png)
* 100 tūkst. studentų generavimo laiko testavimų lentelė

| 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|----------|----------|----------|----------|----------|----------|
| 0.2945 s | 0.2831 s | 0.2908 s | 0.2855 s | 0.2829 s | 0.2873 s |

### 4) Testuosiu 1 milijono studentų failo sukūrimo ir uždarymo laiką.
* Kai yra 1 milijonas studentų, kiekvienas turi po 7 namų darbus ir vieną egzamino rezultatą.
* Pirmas bandymas:

![alt text](./images/image-1.png)
* 1 milijono studentų generavimo laiko testavimų lentelė

| 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|----------|----------|----------|----------|----------|----------|
| 2.2452 s | 2.1820 s | 2.1587 s | 2.3350 s | 2.2060 s | 2.2253 s |

### 5) Testuosiu 10 milijonų studentų failo sukūrimo ir uždarymo laiką.
* Kai yra 10 milijonų studentų, kiekvienas turi po 5 namų darbus ir vieną egzamino rezultatą.
* Pirmas bandymas:

![alt text](./images/image-4.png)
* 10 milijonų studentų generavimo laiko testavimų lentelė

| 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|----------|----------|----------|----------|----------|----------|
| 20.786 s | 22.255 s | 21.093 s | 20.908 s | 21.502 s | 21.308 s |

## 2 Tyrimas:
### 1) Testuosiu 1 tūkstančio studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos programos veikimo laiką.
* Pirmas bandymas:

![alt text](./images/image-5.png)
![alt text](./images/image-6.png)
* 1 tūkst. studentų laiko testavimų lentelė

| Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|----------|----------|----------|----------|----------|----------|
| Nuskaitymas | 0.0033 s | 0.0017 s | 0.0029 s | 0.0033 s | 0.0027 s | 0.0027 s |
| Rūšiavimas  | 0.0019 s | 0.0018 s | 0.0020 s | 0.0005 s | 0.0016 s | 0.0015 s |
| Išvedimas   | 0.0122 s | 0.0058 s | 0.0145 s | 0.0057 s | 0.0137 s | 0.0103 s |
| Vykdymas    | 0.0335 s | 0.0153 s | 0.0364 s | 0.0183 s | 0.0288 s | 0.0264 s |

### 2) Testuosiu 10 tūkstančių studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos programos veikimo laiką.
* Pirmas bandymas:

![alt text](./images/image-7.png)
![alt text](./images/image-8.png)
* 10 tūkst. studentų laiko testavimų lentelė

| Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|----------|----------|----------|----------|----------|----------|
| Nuskaitymas | 0.0225 s | 0.0162 s | 0.0147 s | 0.0167 s | 0.0160 s | 0.0172 s |
| Rūšiavimas  | 0.0030 s | 0.0024 s | 0.0026 s | 0.0025 s | 0.0027 s | 0.0026 s |
| Išvedimas   | 0.0334 s | 0.0350 s | 0.0348 s | 0.0295 s | 0.0434 s | 0.0352 s |
| Vykdymas    | 0.1045 s | 0.1225 s | 0.0973 s | 0.0902 s | 0.1054 s | 0.1039 s |

### 3) Testuosiu 100 tūkstančių studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos programos veikimo laiką.
* Pirmas bandymas:

![alt text](./images/image-9.png)
![alt text](./images/image-10.png)
* 100 tūkst. studentų laiko testavimų lentelė

| Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|----------|----------|----------|----------|----------|----------|
| Nuskaitymas | 0.1659 s | 0.1538 s | 0.1474 s | 0.1463 s | 0.1419 s | 0.1510 s |
| Rūšiavimas  | 0.0183 s | 0.0224 s | 0.0144 s | 0.0226 s | 0.0151 s | 0.0185 s |
| Išvedimas   | 0.2317 s | 0.3066 s | 0.2719 s | 0.3195 s | 0.3220 s | 0.2903 s |
| Vykdymas    | 0.6698 s | 0.8447 s | 0.7171 s | 0.7885 s | 0.8503 s | 0.7740 s |

### 4) Testuosiu 1 milijono studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos programos veikimo laiką.
* Pirmas bandymas:

![alt text](./images/image-11.png)
![alt text](./images/image-12.png)
* 1 milijonų studentų laiko testavimų lentelė

| Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|----------|----------|----------|----------|----------|----------|
| Nuskaitymas | 0.7563 s | 0.8295 s | 0.7762 s | 0.7925 s | 0.7996 s | 0.7908 s |
| Rūšiavimas  | 0.1044 s | 0.1073 s | 0.1048 s | 0.1444 s | 0.1061 s | 0.1134 s |
| Išvedimas   | 2.4068 s | 2.3731 s | 2.3550 s | 2.2063 s | 2.2354 s | 2.3153 s |
| Vykdymas    | 6.7096 s | 5.9877 s | 5.9002 s | 5.6726 s | 5.7194 s | 5.9979 s |

### 5) Testuosiu 10 milijonų studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos programos veikimo laiką.
* Pirmas bandymas:

![alt text](./images/image-13.png)
![alt text](./images/image-14.png)
* 10 milijonų studentų laiko testavimų lentelė

| Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|----------|----------|----------|----------|----------|----------|
| Nuskaitymas | 6.9711 s | 6.9106 s | 6.9154 s | 6.8950 s | 6.8858 s | 6.9155 s |
| Rūšiavimas  | 2.0562 s | 1.1321 s | 1.1247 s | 1.3328 s | 2.2125 s | 1.5716 s |
| Išvedimas   | 22.625 s | 22.870 s | 22.930 s | 23.087 s | 23.175 s | 22.937 s |
| Vykdymas    | 57.542 s | 58.066 s | 59.858 s | 59.207 s | 57.399 s | 58.414 s |



# v1.0 Tyrimai (Konteinerių testavimas)
### Mano nešiojamo kompiuterio (kurį naudoju testavimui) parametrai: 
* CPU: 13th Gen Intel(R) Core(TM) i7-13700H 2.40 GHz;
* RAM: 32 GB;
* System type: 64-bit operating system, x64-based processor;
* SSD: 500 GB.
### Testuoju, kai bendrą studentų konteinerį skaidau į du naujus to paties tipo konteinerius: "kietiakiai" ir "nuskriaustukai". Techniškai 1 strategija.
### "Rūšiavimas" reiškia studentų rūšiavimą didėjimo tvarką konteineryje su sort.
### "Skirstymas" reiškia studentų skirstymo į dvi grupes/kategorijas (naujų konteinerių su skirtingais studentais kūrimas).

## 1 Tyrimas (Be strategijų)
### 1) Testuosiu 1 tūkstančio studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtingais konteineriais.

| Konteineris | Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|-------------|----------|----------|----------|----------|----------|----------|
| Vektorius   | Nuskaitymas | 0.0028 s | 0.0053 s | 0.0048 s | 0.0030 s | 0.0056 s | 0.0043 s |
| Vektorius   | Rūšiavimas  | 0.404 ms | 0.301 ms | 0.231 ms | 0.185 ms | 0.266 ms | 0.277 ms |
| Vektorius   | Skirstymas  | 0.0072 s | 0.0031 s | 0.0030 s | 0.0022 s | 0.0025 s | 0.0036 s |
| List        | Nuskaitymas | 0.0047 s | 0.0064 s | 0.0069 s | 0.0070 s | 0.0048 s | 0.0059 s |
| List        | Rūšiavimas  | 0.247 ms | 0.168 ms | 0.209 ms | 0.157 ms | 0.460 ms | 0.249 ms |
| List        | Skirstymas  | 0.0035 s | 0.0036 s | 0.0035 s | 0.0034 s | 0.0035 s | 0.0034 s |
| Deque       | Nuskaitymas | 0.0063 s | 0.0059 s | 0.0042 s | 0.0056 s | 0.0031 s | 0.0050 s |
| Deque       | Rūšiavimas  | 0.858 ms | 0.839 ms | 0.288 ms | 0.858 ms | 0.464 ms | 0.661 ms |
| Deque       | Skirstymas  | 0.0033 s | 0.0033 s | 0.0028 s | 0.0034 s | 0.0034 s | 0.0032 s |

### 2) Testuosiu 10 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtingais konteineriais.

| Konteineris | Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|-------------|----------|----------|----------|----------|----------|----------|
| Vektorius   | Nuskaitymas | 0.0077 s | 0.0081 s | 0.0072 s | 0.0059 s | 0.0069 s | 0.0071 s |
| Vektorius   | Rūšiavimas  | 0.0021 s | 0.0018 s | 0.0018 s | 0.0017 s | 0.0008 s | 0.0016 s |
| Vektorius   | Skirstymas  | 0.0044 s | 0.0045 s | 0.0043 s | 0.0041 s | 0.0041 s | 0.0043 s |
| List        | Nuskaitymas | 0.0093 s | 0.0057 s | 0.0092 s | 0.0087 s | 0.0069 s | 0.0080 s |
| List        | Rūšiavimas  | 0.0011 s | 0.0013 s | 0.0021 s | 0.0012 s | 0.0013 s | 0.0014 s |
| List        | Skirstymas  | 0.0031 s | 0.0032 s | 0.0044 s | 0.0039 s | 0.0012 s | 0.0032 s |
| Deque       | Nuskaitymas | 0.0111 s | 0.0096 s | 0.0112 s | 0.0108 s | 0.0067 s | 0.0099 s |
| Deque       | Rūšiavimas  | 0.0036 s | 0.0038 s | 0.0087 s | 0.0026 s | 0.0028 s | 0.0043 s |
| Deque       | Skirstymas  | 0.0071 s | 0.0073 s | 0.0052 s | 0.0055 s | 0.0055 s | 0.0061 s |

### 3) Testuosiu 100 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtingais konteineriais.

| Konteineris | Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|-------------|----------|----------|----------|----------|----------|----------|
| Vektorius   | Nuskaitymas | 0.1626 s | 0.1572 s | 0.1627 s | 0.0181 s | 0.1618 s | 0.1329 s |
| Vektorius   | Rūšiavimas  | 0.0210 s | 0.0232 s | 0.0211 s | 0.0233 s | 0.0221 s | 0.0220 s |
| Vektorius   | Skirstymas  | 0.0212 s | 0.0226 s | 0.0181 s | 0.0222 s | 0.0164 s | 0.0206 s |
| List        | Nuskaitymas | 0.3337 s | 0.3353 s | 0.3407 s | 0.3309 s | 0.2808 s | 0.3087 s |
| List        | Rūšiavimas  | 0.0096 s | 0.0098 s | 0.0113 s | 0.0102 s | 0.0105 s | 0.0101 s |
| List        | Skirstymas  | 0.0802 s | 0.0875 s | 0.0785 s | 0.0847 s | 0.0875 s | 0.0842 s |
| Deque       | Nuskaitymas | 0.1742 s | 0.1392 s | 0.1739 s | 0.1724 s | 0.1507 s | 0.1556 s |
| Deque       | Rūšiavimas  | 0.0587 s | 0.0490 s | 0.0589 s | 0.0535 s | 0.0591 s | 0.0572 s |
| Deque       | Skirstymas  | 0.0343 s | 0.0428 s | 0.0417 s | 0.0441 s | 0.0385 s | 0.0402 s |

### 4) Testuosiu 1 milijono studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtingais konteineriais.

| Konteineris | Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|-------------|----------|----------|----------|----------|----------|----------|
| Vektorius   | Nuskaitymas | 0.7476 s | 0.7022 s | 0.6937 s | 0.7392 s | 0.7067 s | 0.7177 s |
| Vektorius   | Rūšiavimas  | 0.2702 s | 0.2695 s | 0.2626 s | 0.1420 s | 0.2713 s | 0.2335 s |
| Vektorius   | Skirstymas  | 0.1249 s | 0.1290 s | 0.1240 s | 0.1626 s | 0.1215 s | 0.1336 s |
| List        | Nuskaitymas | 1.3862 s | 1.3127 s | 1.3149 s | 1.1616 s | 1.4077 s | 1.3162 s |
| List        | Rūšiavimas  | 0.1112 s | 0.1223 s | 0.1149 s | 0.1137 s | 0.1295 s | 0.1214 s |
| List        | Skirstymas  | 0.2876 s | 0.2779 s | 0.3099 s | 0.2939 s | 0.2934 s | 0.2936 s |
| Deque       | Nuskaitymas | 0.9095 s | 0.8445 s | 0.8945 s | 0.8914 s | 0.8429 s | 0.8769 s |
| Deque       | Rūšiavimas  | 0.6868 s | 0.6954 s | 0.6877 s | 0.6779 s | 0.6919 s | 0.6855 s |
| Deque       | Skirstymas  | 0.2802 s | 0.2794 s | 0.2904 s | 0.2773 s | 0.2757 s | 0.2802 s |

### 5) Testuosiu 10 milijonų studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtingais konteineriais.

| Konteineris | Matavimas   | 1 testas | 2 testas | 3 testas | 4 testas | 5 testas | Vidurkis |
|-------------|-------------|----------|----------|----------|----------|----------|----------|
| Vektorius   | Nuskaitymas | 6.5782 s | 7.0003 s | 7.0122 s | 7.2107 s | 7.0148 s | 6.9005 s |
| Vektorius   | Rūšiavimas  | 3.4127 s | 3.3642 s | 3.4868 s | 3.7064 s | 3.5045 s | 3.4744 s |
| Vektorius   | Skirstymas  | 1.3234 s | 1.2963 s | 1.3420 s | 1.3275 s | 1.3065 s | 1.3185 s |
| List        | Nuskaitymas | 9.2979 s | 10.866 s | 11.166 s | 11.125 s | 10.096 s | 10.110 s |
| List        | Rūšiavimas  | 1.4131 s | 1.4196 s | 1.4264 s | 1.4338 s | 1.4101 s | 1.4260 s |
| List        | Skirstymas  | 2.4258 s | 2.3532 s | 2.5715 s | 2.4044 s | 2.6163 s | 2.4660 s |
| Deque       | Nuskaitymas | 7.7895 s | 8.0954 s | 9.2386 s | 8.1529 s | 8.2182 s | 8.3126 s |
| Deque       | Rūšiavimas  | 8.8716 s | 8.3875 s | 8.3435 s | 8.3998 s | 8.4138 s | 8.2840 s |
| Deque       | Skirstymas  | 3.1646 s | 3.0068 s | 3.0522 s | 3.2564 s | 3.0442 s | 3.1044 s |

### Taigi, iš konteinerių testavimo matome, kad greičiausiai rūšiuoja (su sort) list konteineris,
### tačiau greičiausiai nuskaito ir skirsto į dvi grupes vector konteineris.