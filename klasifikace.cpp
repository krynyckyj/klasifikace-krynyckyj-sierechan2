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
double prumerStudenta(const int (&z)[STUDENTI][PREDMETY], int student);
double prumerPredmetu(const int (&z)[STUDENTI][PREDMETY], int predmet);

void vypisTabulku(const int (&z)[STUDENTI][PREDMETY]) {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::setw(8) << "";
    for (size_t p = 0; p < predmety.size(); p++) {
        std::cout << std::setw(6) << predmety[p];
    }
    std::cout << std::setw(8) << "prumer" << "\n";

    for (size_t s = 0; s < jmena.size(); s++) {
        std::cout << std::setw(8) << jmena[s];
        for (size_t p = 0; p < predmety.size(); p++) {
            std::cout << std::setw(6) << z[s][p];
        }
        std::cout << std::setw(8) << prumerStudenta(z, s) << "\n";
    }

    std::cout << std::setw(8) << "prumer";
    for (size_t p = 0; p < predmety.size(); p++) {
        std::cout << std::setw(6) << prumerPredmetu(z, p);
    }
    std::cout << "\n";
}

int prvniStudentSeZnamkou(const int (&z)[STUDENTI][PREDMETY], int znamka) {
    for (size_t s = 0; s < jmena.size(); s++) {
        for (size_t p = 0; p < predmety.size(); p++) {
            if (z[s][p] == znamka) {
                return s;
            }
        }
    }
    return -1;
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

int main() {
    // --- student A ---
    vypisTabulku(znamky);

    int petka = prvniStudentSeZnamkou(znamky, 5);
    if (petka == -1) {
        std::cout << "Petku nema nikdo\n";
    } else {
        std::cout << "Prvni s petkou: " << jmena[petka] << "\n";
    }

    int sestka = prvniStudentSeZnamkou(znamky, 6);
    if (sestka == -1) {
        std::cout << "Sestku nema nikdo\n";
    } else {
        std::cout << "Prvni se sestkou: " << jmena[sestka] << "\n";
    }

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
