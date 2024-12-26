# Proiect: Platforma pentru Gestionarea Lucrarilor

## Descriere
Acest proiect implementeaza o platforma software care faciliteaza gestionarea si procesarea lucrarilor academice. Utilizatorii pot incarca fisiere text care contin citate si bibliografii, iar aplicatia extrage si organizeaza aceste informatii intr-o structura usor de accesat. Proiectul include un meniu interactiv care permite gestionarea platformei si a lucrarilor printr-o interfata de tip consola.

## Functionalitati
- **Incarcare lucrari:** Permite incarcarea de fisiere care contin citate si bibliografii, folosind functia `citesteLucrareFisier`.
- **Procesare:** Extrage automat citatele si bibliografiile si le stocheaza in obiecte de tip `Citat` si `Bibliografie`.
- **Meniu interactiv:** Ofera optiuni pentru crearea, gestionarea si salvarea unei platforme, utilizand clasa `Menu`.
- **Afisare:** Listeaza lucrarile, citatele si bibliografiile intr-o forma ordonata.
- **Sortare:** Ofera functionalitati de sortare alfabetica dupa nume sau autor.
- **Generare rapoarte:** Verifica daca un citat sau o bibliografie apare in lucrari si afiseaza rezultatele.
- **Persistenta:** Suporta salvarea si incarcarea datelor in/din fisiere text.

## Structura Proiectului
- `main.cpp`: Punctul de intrare al aplicatiei, utilizeaza un meniu pentru a interactiona cu utilizatorul prin intermediul clasei `Menu`.
- `menu.h`: Declaratia clasei `Menu`, care implementeaza meniul principal si functionalitatile aferente.
- `platforma.h` / `platforma.cpp`: Contine logica platformei, inclusiv functiile de gestionare a lucrarilor, citatelor si bibliografiilor.
- `citat.h`: Defineste clasa `Citat`, care reprezinta un citat cu continut si autor.
- `Test.txt` / `Test2.txt`: Fisiere de test care contin exemple de lucrari cu citate si bibliografii.

## Exemple de Date
**Test.txt:**
```
3
lucrare1
2 2
Este important sa invatam constant.
Albert Einstein
Creativitatea este inteligenta care se distreaza.
Albert Einstein
Fundamentele programarii
John Doe
Ghid practic de scriere academica
Jane Smith
lucrare2
2 2
AI nu inlocuieste inteligenta umana, ci o amplifica.
Andrew Ng
Viitorul apartine celor care isi controleaza tehnologia.
Elon Musk
Introducere in Machine Learning
Ian Goodfellow
Deep Learning
Yoshua Bengio
lucrare3
2 2
Arta este o minciuna care ne ajuta sa spunem adevarul.
Pablo Picasso
Scrisul este gandirea care devine vizibila.
Stephen King
Lumea ca vointa si reprezentare
Arthur Schopenhauer
Estetica poeziei moderne
Paul Valery
```

**Test2.txt:**
```
1
lucrare2
2 2
AI nu inlocuieste inteligenta umana, ci o amplifica.
Andrew Ng
Viitorul apartine celor care isi controleaza tehnologia.
Elon Musk
Introducere in Machine Learning
Ian Goodfellow
Deep Learning
Yoshua Bengio
```

## Functionalitati ale Meniului Interactiv
Meniul implementat in `menu.h` si `menu.cpp` ofera urmatoarele optiuni:
1. **Incarcare platforma**: Permite incarcarea unei platforme existente dintr-un fisier text.
2. **Creare platforma noua**: Creeaza o platforma noua, cu un nume specificat de utilizator.
3. **Introducere lucrare**:
   - De la tastatura: Permite introducerea manuala a lucrarilor, incluzand citate si bibliografii.
   - Din fisier: Incarca lucrari din fisiere text externe.
4. **Cautare**:
   - Cautare citat: Verifica daca un citat este prezent in lucrari si afiseaza locatia acestuia.
   - Cautare bibliografie: Verifica daca o bibliografie este utilizata in lucrari.
   - Cautare lucrare: Afiseaza continutul unei lucrari specifice.
5. **Afisare**:
   - Afisare citate si bibliografii: Listeaza toate citatele si bibliografiile din platforma, ordonate alfabetic.
   - Afisare lucrari: Afiseaza toate lucrarile din platforma.
6. **Salvare**: Salveaza datele curente ale platformei intr-un fisier text.
7. **Iesire**: Permite revenirea la meniul principal sau iesirea din aplicatie.

## Instalare
1. Cloneaza repository-ul:
   ```bash
   git clone https://github.com/utilizator/platforma-gestionare-lucrari.git
   ```
2. Compileaza codul:
   ```bash
   g++ -std=c++17 -o platforma main.cpp platforma.cpp -I.
   ```
3. Ruleaza aplicatia:
   ```bash
   ./platforma
   ```

## Utilizare
- Incarca fisiere text cu lucrari folosind functia de meniu.
- Afiseaza lucrarile, citatele si bibliografiile stocate.
- Sorteaza citatele si bibliografiile dupa nume sau autor.
- Genereaza rapoarte pentru a verifica prezenta anumitor citate sau bibliografii.

## Contributii
Contributiile sunt binevenite! Urmeaza acesti pasi:
1. Realizeaza un fork la repository.
2. Creeaza o ramura noua:
   ```bash
   git checkout -b functionalitate-noua
   ```
3. Adauga modificarile tale.
4. Trimite un pull request.

## Licenta
Acest proiect este licentiat sub [MIT License](LICENSE).

