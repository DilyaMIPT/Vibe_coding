// include/WordList.h
#ifndef WORD_LIST_H
#define WORD_LIST_H

#include <string>
#include <array>
#include <random>

namespace WordList {
    const std::array<std::string, 40> words = {{
    "COMPILE", "INTEGER", "RUNTIME", "POINTER", "VIRTUAL",
    "ALGEBRA", "THEOREM", "FORMULA", "DECIMAL", "COMPLEX",
    "QUANTUM", "GRAVITY", "NEUTRON", "NUCLEAR", "KINETIC",
    "ELEMENT", "ORGANIC", "SOLVENT", "CRYSTAL", "POLYMER",
    "BOOLEAN", "STATICS", "DYNAMIC", "VECTORS", "SCALARS",
    "NUCLEUS", "PROTONS", "PHOTONS", "ISOTOPE", "ENZYMES",
    "ACIDITY", "OXIDIZE", "REDUCES", "SOLUTES", "MIXTURE",
    "ENTROPY", "THERMAL", "OPTICAL", "WAVELET", "LOGICAL"
}};

    inline std::string getRandomWord() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, words.size() - 1);
        return words[dist(gen)];
    }
}

#endif // WORD_LIST_H