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