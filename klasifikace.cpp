#include <iostream>
#include <iomanip>     // std::setw, std::setprecision
#include <array>
#include <string>
#include <algorithm>   // std::sort

const int STUDENTI = 6;
const int PREDMETY = 4;

std::array<std::string, STUDENTI> jmena = {"Adam", "Eva", "Jan", "Lucie", "Marek", "Petra"};
std::array<std::string, PREDMETY> predmety = {"PRG", "MAT", "CJL", "ANJ"};

int znamky[STUDENTI][PREDMETY] = {
    {1, 2, 3, 1},
    {2, 2, 1, 1},
    {3, 4, 2, 3},
    {1, 1, 1, 2},
    {5, 3, 4, 4},
    {2, 3, 2, 2}
};

// ===== Funkce – student A =====
void vypisTabulku(const int (&z)[STUDENTI][PREDMETY]) {
    std::cout << std::setw(8) << "";
    for (size_t p = 0; p < predmety.size(); p++) {
        std::cout << std::setw(6) << predmety[p];
    }
    std::cout << "\n";

    for (size_t s = 0; s < jmena.size(); s++) {
        std::cout << std::setw(8) << jmena[s];
        for (size_t p = 0; p < predmety.size(); p++) {
            std::cout << std::setw(6) << z[s][p];
        }
        std::cout << "\n";
    }
}

// ===== Funkce – student B =====

double prumerStudenta(const int (&z)[STUDENTI][PREDMETY], int student) {
    int soucet = 0;
    for (size_t p = 0; p < predmety.size(); p++) {
        soucet += z[student][p];
    }
    return static_cast<double>(soucet) / predmety.size();
}

double prumerPredmetu(const int (&z)[STUDENTI][PREDMETY], int predmet) {
    int soucet = 0;
    for (size_t s = 0; s < jmena.size(); s++) {
        soucet += z[s][predmet];
    }
    return static_cast<double>(soucet) / jmena.size();
}

template<typename T>
int indexMinima(const T pole[], int velikost) {
    int index = 0;
    for (int i = 1; i < velikost; i++) {
        if (pole[i] < pole[index]) {
            index = i;
        }
    }
    return index;
}

template<typename T>
int indexMaxima(const T pole[], int velikost) {
    int index = 0;
    for (int i = 1; i < velikost; i++) {
        if (pole[i] > pole[index]) {
            index = i;
        }
    }
    return index;
}

int main() {
    // --- student A ---
    vypisTabulku(znamky);

    // --- student B ---
    double prumery[STUDENTI];
    for (size_t s = 0; s < jmena.size(); s++) {
        prumery[s] = prumerStudenta(znamky, s);
    }
    std::cout << "Nejlepsi: " << jmena[indexMinima(prumery, STUDENTI)] << "\n";
    std::cout << "Nejhorsi: " << jmena[indexMaxima(prumery, STUDENTI)] << "\n";

    return 0;
}
