/*
** EPITECH PROJECT, 2022
** Motus
** File description:
** main.cpp
*/

#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <time.h>

#include <iostream>

#include "motus.hpp"

/// @brief Function that choose a random word in the game's dictionary.
/// @param dictionary the actual dictionary of the game.
/// @return the choosen word.
static std::string chooseRandomWord(std::vector<std::string> const &dictionary)
{
    std::srand(time(nullptr));
    unsigned long r = rand() % dictionary.size();
    return (dictionary[r]);
}

/// @brief Create the dictionary for the motus game.
/// @param filepath the filepath that store the list of words used by the game.
/// @return a vector of string that store all words.
static std::vector<std::string> createDictionary(char const * const filepath)
{
    std::fstream fs;
    std::vector<std::string> dictionary;
    std::string line;

    fs.open(filepath);
    if (!fs.good()) {
        fs.close();
        return (dictionary);
    }
    while (!fs.eof()) {
        std::getline(fs, line);
        dictionary.push_back(line);
    }
    fs.close();
    return (dictionary);
}

/// @brief main function.
/// @param argc number of arguments passed to the program.
/// @param argv list of arguments passed to the program.
/// @return 0 in case of success. Any other value means the program throw an error.
int main(int const argc, char const * const * const argv)
{
    std::string word;
    std::vector<std::string> dictionary;

    if (argc < 2 || argc > 3)
        return (84);
    if (argv == nullptr)
        return (84);
    dictionary = createDictionary(argv[1]);
    if (!dictionary.size())
        return (84);
    if (argc == 2)
        return (motus(dictionary, chooseRandomWord(dictionary)));
    return (motus(dictionary, argv[2]));
}