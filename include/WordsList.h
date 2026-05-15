// include/WordList.h
#ifndef WORD_LIST_H
#define WORD_LIST_H

#include <string>
#include <array>
#include <random>

namespace WordList {
    const std::array<std::string, 40> words = {{
    "BANANAS", "MONSTER", "PENGUIN", "POPCORN", "UNICORN",
    "CHICKEN", "PIRATES", "BUBBLES", "MAGICAL", "DANCING",
    "SUNSHINE", "COOKIES", "BALLOON", "MYSTERY", "RAINBOW",
    "ICECREAM", "MONKEYS", "PUMPKIN", "TREASURE", "JOURNEY",
    "CUPCAKE", "WHISTLE", "GIRAFFE", "CAMPING", "TICKETS",
    "WIZARDS", "ROCKETS", "PIZZAZZ", "CANDLES", "DINNERS",
    "SMILING", "JUNGLES", "SANDWICH", "MIRACLE", "BICYCLE",
    "FLOWERS", "HAPPILY", "CARTOON", "TROPICS", "THUNDER"
}};

    inline std::string getRandomWord() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, words.size() - 1);
        return words[dist(gen)];
    }
}

#endif // WORD_LIST_H