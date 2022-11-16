/*
** EPITECH PROJECT, 2022
** Motus
** File description:
** motus.hpp
*/

#ifndef MY_MOTUS_HPP_
    #define MY_MOTUS_HPP_

    #include <vector>
    #include <string>

    int motus(std::vector<std::string> const &dictionary, std::string const &string);
    int algo(char const * const * const dictionary, size_t const dictionary_size, char const * const word, size_t const word_length);
    void guess(char const * const guess, char const * const word, char * result);
    char *emptyStr(std::size_t const &word_length);

#endif