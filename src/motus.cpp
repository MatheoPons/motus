/*
** EPITECH PROJECT, 2022
** Motus
** File description:
** motus.cpp
*/

#include <vector>
#include <string>
#include <iostream>
#include <cstring>

#include "motus.hpp"

/// @brief Alloc str to '_' with a length of word_length
/// @param word_length size of the string you want to alloc
/// @return adress of the allocated string
char *emptyStr(std::size_t const &word_length)
{
    char *str;
    std::size_t idx = 0;
    
    str = (char *)malloc(sizeof(char) * (word_length + 1));
    if (!str)
        return NULL;
    str[word_length] = '\0';
    while (idx < word_length) {
        str[idx] = '_';
        idx = idx + 1;
    }
    return str;
}

/// @brief let the player try a word '%':good place '$':good letter '_':wrong letter
/// @param guess
/// @param word
/// @param result
/// @return a string containing 3 char : '%':good place '$':good letter '_':wrong letter
void guess(char const * const guess, char const * const word, char * result)
{
    static std::size_t guessNumber = 1;
    std::string sresult;
    std::string sguess{guess};
    std::string sword{word};
    std::size_t idx = 0;

    while (idx < sguess.size()) {
        if (sguess[idx] == sword[idx])
            sresult.push_back('$');
        else if (sword.find_first_of(sguess[idx]) != std::string::npos)
            sresult.push_back('%');
        else
            sresult.push_back('_');
        idx = idx + 1;
    }
    std::cout << "[" << guessNumber << "]: " << guess << " ? " << word << " => " << sresult << std::endl;
    strcpy(result, sresult.c_str());
}

/// @brief main function of the program
/// @param dictionary list of words for the current game
/// @param word the word the player have to ind
/// @return program state
int motus(std::vector<std::string> const &dictionary, std::string const &word)
{
    std::vector<char*> cdictionary;

    cdictionary.reserve(dictionary.size());
    for(size_t idx = 0; idx < dictionary.size(); ++idx)
        cdictionary.push_back(const_cast<char*>(dictionary[idx].c_str()));
    if (!cdictionary.empty())
        return (algo(&cdictionary[0], cdictionary.size(), word.c_str(), word.size()));
    return (84);
}
