/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "My Project", "index.html", [
    [ "Versijų aprašymai:", "md__r_e_a_d_m_e.html", [
      [ "v.pradinė:", "md__r_e_a_d_m_e.html#autotoc_md1", [
        [ "Duomenų nuskaitymas, studentų struktūros sukūrimas, galutinio balo suskaičiavimas", "md__r_e_a_d_m_e.html#autotoc_md2", null ],
        [ "su vidurkiu arba mediana. Taip pat ir duomenų išvedimas.", "md__r_e_a_d_m_e.html#autotoc_md3", null ]
      ] ],
      [ "v0.1:", "md__r_e_a_d_m_e.html#autotoc_md4", [
        [ "Padaryta, kad programa veiktų, nežinant kiek bus namų darbų ar studentų ir realizuota", "md__r_e_a_d_m_e.html#autotoc_md5", null ],
        [ "su C masyvu ir vektoriais. Dar padaryta, kad vartotojas galėtų pasirinkti sugeneruoti duomenis.", "md__r_e_a_d_m_e.html#autotoc_md6", null ]
      ] ],
      [ "v0.2:", "md__r_e_a_d_m_e.html#autotoc_md7", [
        [ "Padaryta, kad duomenis eitų gauti iš tekstinio failo ir kad naudotojas galėtų pasirinkti,", "md__r_e_a_d_m_e.html#autotoc_md8", null ],
        [ "pagal ką rūšiuoti. Taip pat reikėjo ištestuoti skirtingo dydžio failus (greitį).", "md__r_e_a_d_m_e.html#autotoc_md9", null ]
      ] ],
      [ "v0.3:", "md__r_e_a_d_m_e.html#autotoc_md10", [
        [ "Kur tikslinga programoje pradėta naudoti struktūras, daug funkcijų ir duomenų tipų perkėlti", "md__r_e_a_d_m_e.html#autotoc_md11", null ],
        [ "į skirtingus header ar .cpp files. Pridėtas minimalus išimčių valdymas.", "md__r_e_a_d_m_e.html#autotoc_md12", null ]
      ] ],
      [ "v0.4:", "md__r_e_a_d_m_e.html#autotoc_md13", [
        [ "Sukurta failų generavimo funkcija, surūšiuoti studentai pagal dvi kategorijas", "md__r_e_a_d_m_e.html#autotoc_md14", null ],
        [ "(nuskriaustukai, jei galutinis balas < 5.0, o kietiakai, jei galutinis balas >= 5....", "md__r_e_a_d_m_e.html#autotoc_md15", null ],
        [ "ir jie išvesti į du skirtingus failus.", "md__r_e_a_d_m_e.html#autotoc_md16", null ],
        [ "Atlikta programos veikimo greičio (spartos) analizė.", "md__r_e_a_d_m_e.html#autotoc_md17", null ]
      ] ],
      [ "v1.0:", "md__r_e_a_d_m_e.html#autotoc_md18", [
        [ "Konteinerių testavimas (sukurtos list ir deque programos ir visų laikai ištestuoti priskaitant vektor...", "md__r_e_a_d_m_e.html#autotoc_md19", null ],
        [ "Optimizuota studentų rūšiavimo (dalijimo) į dvi kategorijas realizacija.", "md__r_e_a_d_m_e.html#autotoc_md20", null ]
      ] ],
      [ "v0.4 Tyrimai", "md__r_e_a_d_m_e.html#autotoc_md21", [
        [ "1 Tyrimas:", "md__r_e_a_d_m_e.html#autotoc_md22", [
          [ "1) Testuosiu 1 tūkstančio studentų failo sukūrimo ir uždarymo laiką.", "md__r_e_a_d_m_e.html#autotoc_md23", null ],
          [ "2) Testuosiu 10 tūkstančių studentų failo sukūrimo ir uždarymo laiką.", "md__r_e_a_d_m_e.html#autotoc_md24", null ],
          [ "3) Testuosiu 100 tūkstančių studentų failo sukūrimo ir uždarymo laiką.", "md__r_e_a_d_m_e.html#autotoc_md25", null ],
          [ "4) Testuosiu 1 milijono studentų failo sukūrimo ir uždarymo laiką.", "md__r_e_a_d_m_e.html#autotoc_md26", null ],
          [ "5) Testuosiu 10 milijonų studentų failo sukūrimo ir uždarymo laiką.", "md__r_e_a_d_m_e.html#autotoc_md27", null ]
        ] ],
        [ "2 Tyrimas:", "md__r_e_a_d_m_e.html#autotoc_md28", [
          [ "1) Testuosiu 1 tūkstančio studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos ...", "md__r_e_a_d_m_e.html#autotoc_md29", null ],
          [ "2) Testuosiu 10 tūkstančių studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos...", "md__r_e_a_d_m_e.html#autotoc_md30", null ],
          [ "3) Testuosiu 100 tūkstančių studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir viso...", "md__r_e_a_d_m_e.html#autotoc_md31", null ],
          [ "4) Testuosiu 1 milijono studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos pr...", "md__r_e_a_d_m_e.html#autotoc_md32", null ],
          [ "5) Testuosiu 10 milijonų studentų failo nuskaitymo, rūšiavimo, išvedimo į du naujus failus ir visos p...", "md__r_e_a_d_m_e.html#autotoc_md33", null ]
        ] ]
      ] ],
      [ "v1.0 Tyrimai (Konteinerių testavimas)", "md__r_e_a_d_m_e.html#autotoc_md34", [
        [ "1 Tyrimas (Be strategijų)", "md__r_e_a_d_m_e.html#autotoc_md39", [
          [ "Mano nešiojamo kompiuterio (kurį naudoju testavimui) parametrai:", "md__r_e_a_d_m_e.html#autotoc_md35", null ],
          [ "Testuoju, kai bendrą studentų konteinerį skaidau į du naujus to paties tipo konteinerius: \"kietiakiai...", "md__r_e_a_d_m_e.html#autotoc_md36", null ],
          [ "\"Rūšiavimas\" reiškia studentų rūšiavimą didėjimo tvarką konteineryje su sort.", "md__r_e_a_d_m_e.html#autotoc_md37", null ],
          [ "\"Skirstymas\" reiškia studentų skirstymo į dvi grupes/kategorijas (naujų konteinerių su skirtingais st...", "md__r_e_a_d_m_e.html#autotoc_md38", null ],
          [ "1) Testuosiu 1 tūkstančio studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirt...", "md__r_e_a_d_m_e.html#autotoc_md40", null ],
          [ "2) Testuosiu 10 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skir...", "md__r_e_a_d_m_e.html#autotoc_md41", null ],
          [ "3) Testuosiu 100 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su ski...", "md__r_e_a_d_m_e.html#autotoc_md42", null ],
          [ "4) Testuosiu 1 milijono studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtin...", "md__r_e_a_d_m_e.html#autotoc_md43", null ],
          [ "5) Testuosiu 10 milijonų studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirti...", "md__r_e_a_d_m_e.html#autotoc_md44", null ],
          [ "Taigi, iš konteinerių testavimo matome, kad greičiausiai rūšiuoja (su sort) list konteineris,", "md__r_e_a_d_m_e.html#autotoc_md45", null ],
          [ "tačiau greičiausiai nuskaito ir skirsto į dvi grupes Vector konteineris.", "md__r_e_a_d_m_e.html#autotoc_md46", null ]
        ] ]
      ] ],
      [ "v1.0 Strategijų tyrimai:", "md__r_e_a_d_m_e.html#autotoc_md47", [
        [ "2 strategijos tyrimas", "md__r_e_a_d_m_e.html#autotoc_md49", [
          [ "Kadangi jau padariau pirmą (1) strategiją praeitame testavime, tai dabar testuosiu antrą (2) ir treči...", "md__r_e_a_d_m_e.html#autotoc_md48", null ],
          [ "1) Testuosiu 1 tūkstančio studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirt...", "md__r_e_a_d_m_e.html#autotoc_md50", null ],
          [ "2) Testuosiu 10 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skir...", "md__r_e_a_d_m_e.html#autotoc_md51", null ],
          [ "3) Testuosiu 100 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su ski...", "md__r_e_a_d_m_e.html#autotoc_md52", null ],
          [ "4) Testuosiu 1 milijono studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirtin...", "md__r_e_a_d_m_e.html#autotoc_md53", null ],
          [ "5) Testuosiu 10 milijono studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi grupes laiką su skirti...", "md__r_e_a_d_m_e.html#autotoc_md54", null ],
          [ "Antros strategijos studentų skirstymo į dvi grupes vietoje aš iš tikro panaudojau 3 strategijos std::...", "md__r_e_a_d_m_e.html#autotoc_md55", null ]
        ] ],
        [ "3 strategijos tyrimas", "md__r_e_a_d_m_e.html#autotoc_md56", [
          [ "Optimizuoju skirstymą su std::copy_if ir std::partition_copy skaidant bendrą konteinerį į du naujus.", "md__r_e_a_d_m_e.html#autotoc_md57", null ],
          [ "1) Testuosiu 1 tūkstančio studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi naujas grupes laiką s...", "md__r_e_a_d_m_e.html#autotoc_md58", null ],
          [ "2) Testuosiu 10 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi naujas grupes laiką ...", "md__r_e_a_d_m_e.html#autotoc_md59", null ],
          [ "3) Testuosiu 100 tūkstančių studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi naujas grupes laiką...", "md__r_e_a_d_m_e.html#autotoc_md60", null ],
          [ "4) Testuosiu 1 milijono studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi naujas grupes laiką su ...", "md__r_e_a_d_m_e.html#autotoc_md61", null ],
          [ "5) Testuosiu 10 milijonų studentų failo nuskaitymo, rūšiavimo, skirstymo į dvi naujas grupes laiką su...", "md__r_e_a_d_m_e.html#autotoc_md62", null ],
          [ "Taigi matome, kad 3 strategija lėtesnė nei 2 ir 1 strategija.", "md__r_e_a_d_m_e.html#autotoc_md63", null ]
        ] ]
      ] ],
      [ "Kaip įdiegti", "md__r_e_a_d_m_e.html#autotoc_md64", null ],
      [ "struct ir class palyginimas, tyrimai:", "md__r_e_a_d_m_e.html#autotoc_md65", [
        [ "Programos veikimo greičio su -O1 testavimas", "md__r_e_a_d_m_e.html#autotoc_md66", null ],
        [ "Programos veikimo greičio su -O2 testavimas", "md__r_e_a_d_m_e.html#autotoc_md67", null ],
        [ "Programos veikimo greičio su -O3 testavimas", "md__r_e_a_d_m_e.html#autotoc_md68", [
          [ "Taigi matome, kad struktūros testai buvo greitesni ir -O3 buvo greičiausias beveik visada.", "md__r_e_a_d_m_e.html#autotoc_md69", null ]
        ] ]
      ] ],
      [ "v1.2 Tyrimai (greitis su perdengtais operatoriais ir be)", "md__r_e_a_d_m_e.html#autotoc_md70", [
        [ "v1.2 greičio tyrimas su 1 milijonu ir 10 milijonų studentų:", "md__r_e_a_d_m_e.html#autotoc_md76", [
          [ "Šiuos perdengtus operatorius naudosiu greičio teste:", "md__r_e_a_d_m_e.html#autotoc_md71", null ],
          [ "Naudosiu pirmą strategiją greičiams matuoti.", "md__r_e_a_d_m_e.html#autotoc_md72", null ],
          [ "Naudosiu -O3 flag.", "md__r_e_a_d_m_e.html#autotoc_md73", null ],
          [ "Perdarysiu testus ir be operatorių perdengimo, nes pakeičiau kode bereikalingus std::endl su \"\\n\".", "md__r_e_a_d_m_e.html#autotoc_md74", null ],
          [ "Ši kodo vieta leidžia pasirinkti, ar naudoti perdengtus operatorius, ar ne:", "md__r_e_a_d_m_e.html#autotoc_md75", null ],
          [ "Paskutinis 1 milijono studentų su operatorių perdengimu testas:", "md__r_e_a_d_m_e.html#autotoc_md77", null ],
          [ "Paskutinis 10 milijonų studentų su operatorių perdengimu testas:", "md__r_e_a_d_m_e.html#autotoc_md78", null ],
          [ "Taigi matome, kad testai su operatorių perdengimu buvo vos lėtesni, nei be, bet galima sakyti beveik ...", "md__r_e_a_d_m_e.html#autotoc_md79", null ]
        ] ]
      ] ],
      [ "v1.5 Tyrimai", "md__r_e_a_d_m_e.html#autotoc_md80", null ],
      [ "v3.0 Vektoriaus kūrimas ir testai", "md__r_e_a_d_m_e.html#autotoc_md89", [
        [ "5 Skirtingų Vector.h funkcijų aprašymas:", "md__r_e_a_d_m_e.html#autotoc_md91", [
          [ "Reikia kompiliuoti su C++20, nes naudojau construct_at() ir destroy_at() metodus, kad realizuoti vekt...", "md__r_e_a_d_m_e.html#autotoc_md90", null ],
          [ "void reserve(std::size_t new_cap) :", "md__r_e_a_d_m_e.html#autotoc_md92", null ],
          [ "void resize(std::size_t new_size) :", "md__r_e_a_d_m_e.html#autotoc_md93", null ],
          [ "iterator insert(const_iterator pos, const T& value) :", "md__r_e_a_d_m_e.html#autotoc_md94", null ],
          [ "template <R> void assign_range(R&& rg) :", "md__r_e_a_d_m_e.html#autotoc_md95", null ],
          [ "template <R> void append_range(R&& rg) :", "md__r_e_a_d_m_e.html#autotoc_md96", null ]
        ] ]
      ] ],
      [ "Efektyvumo/spartos analizė - Vector.h VS std::vector", "md__r_e_a_d_m_e.html#autotoc_md97", [
        [ "10 tūkst. elementų:", "md__r_e_a_d_m_e.html#autotoc_md99", null ],
        [ "100 tūkst. elementų:", "md__r_e_a_d_m_e.html#autotoc_md100", null ],
        [ "1 milijono elementų:", "md__r_e_a_d_m_e.html#autotoc_md101", null ],
        [ "10 milijonų elementų:", "md__r_e_a_d_m_e.html#autotoc_md102", [
          [ "Užpildysime int elementais su push_back()", "md__r_e_a_d_m_e.html#autotoc_md98", null ],
          [ "100 milijonų elementų", "md__r_e_a_d_m_e.html#autotoc_md103", null ]
        ] ],
        [ "Kiek kartų įvyksta konteinerių (Vector ir std::vector) atminties perskirstymai užpildant 100000000 el...", "md__r_e_a_d_m_e.html#autotoc_md104", null ]
      ] ]
    ] ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"_vector_8h_source.html"
];

var SYNCONMSG = 'click to disable panel synchronization';
var SYNCOFFMSG = 'click to enable panel synchronization';