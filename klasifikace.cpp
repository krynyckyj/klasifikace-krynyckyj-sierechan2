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

int main() {
    // --- student A ---
    vypisTabulku(znamky);

    // --- student B ---

    return 0;
}
