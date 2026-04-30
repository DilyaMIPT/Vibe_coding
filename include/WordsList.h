// include/WordList.h
#ifndef WORD_LIST_H
#define WORD_LIST_H

#include <string>
#include <array>
#include <random>

namespace WordList {
    constexpr std::array<std::string, 40> words = {{
        "compile", "integer", "runtime", "pointer", "virtual",
        "algebra", "theorem", "formula", "decimal", "complex",
        "quantum", "gravity", "neutron", "nuclear", "kinetic",
        "element", "organic", "solvent", "crystal", "polymer",
        "boolean", "statics", "dynamic", "vectors", "scalars",
        "nucleus", "protons", "photons", "isotope", "enzymes",
        "acidity", "oxidize", "reduces", "solutes", "mixture",
        "entropy", "thermal", "optical", "wavelet", "logical"
    }};

    inline std::string getRandomWord() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, words.size() - 1);
        return words[dist(gen)];
    }
}

#endif // WORD_LIST_H