// include/WordList.h
#ifndef WORD_LIST_H
#define WORD_LIST_H

#include <string>
#include <array>
#include <random>

namespace WordList {
    const std::array<std::string, 40> words = {{
    "BANANAS", "BURGERS", "POPCORN", "PANCAKE", "CUPCAKE",
    "PICKLES", "BISCUIT", "SAUSAGE", "AVOCADO", "SPINACH",
    "COOKIES", "MUFFINS", "NOODLES", "PRETZEL", "TACOBEL",
    "PANINIS", "CEREALS", "BROWNIE", "CHEESES", "KETCHUP",
    "MUSTARD", "PUDDING", "CROUTON", "MEATBAL", "OREGANO",
    "PEANUTS", "POPCORN", "WALNUTS", "CHERRYS", "MELONSS",
    "PANCAKE", "PICKLES", "MUFFINS", "COOKIES", "PRETZEL",
    "BROWNIE", "NOODLES", "CHEESES", "BANANAS", "BURGERS"
}};

    inline std::string getRandomWord() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, words.size() - 1);
        return words[dist(gen)];
    }
}

#endif // WORD_LIST_H