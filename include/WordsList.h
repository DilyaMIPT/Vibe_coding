// include/WordList.h
#ifndef WORD_LIST_H
#define WORD_LIST_H

#include <string>
#include <array>
#include <random>

namespace WordList {
    const std::array<std::string, 30> words = {{
    "BANANAS", "BURGERS", "PANCAKE", "APRICOT", "PICKLES",
    "BISCUIT", "SPINACH", "COOKIES", "MUFFINS", "NOODLES",
    "PRETZEL", "KETCHUP", "MUSTARD", "PUDDING", "PEANUTS",
    "WALNUTS", "BROWNIE", "TRUFFLE", "LASAGNA", "CARAMEL",
    "CROUTON", "BURRITO", "PARSLEY", "ORANGES", "GRANOLA",
    "WAFFLES", "OATMEAL", "RAVIOLI", "VANILLA", "TACOBEL"
}};

    inline std::string getRandomWord() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, words.size() - 1);
        return words[dist(gen)];
    }
}

#endif // WORD_LIST_H