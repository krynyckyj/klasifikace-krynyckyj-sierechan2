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

int main() {
    // --- student A ---

    // --- student B ---
    // kontrolni vypis prumeru (v casti 2 smazat)
    std::cout << std::fixed << std::setprecision(2);
    for (size_t s = 0; s < jmena.size(); s++) {
        std::cout << jmena[s] << ": " << prumerStudenta(znamky, s) << "\n";
    }
    for (size_t p = 0; p < predmety.size(); p++) {
        std::cout << predmety[p] << ": " << prumerPredmetu(znamky, p) << "\n";
    }

    return 0;
}
