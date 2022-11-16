/*
** EPITECH PROJECT, 2022
** Motus
** File description:
** algo.cpp
*/

#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>

#include "motus.hpp"
#include "list.hpp"

int algo(char const * const * const dictionary, size_t const dictionary_size, char const * const word, size_t const word_length)
{
    char *result = emptyStr(word_length);
    if (!result)
        return (84);
    std::cout << "START:" << std::endl;

    /// WRITE YOUR DEFINITIONS
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->next = NULL;
    if (list == NULL)
        return (84);
    create_list_from_dictionary(dictionary, dictionary_size, list, word_length);

    while (std::string{result}.find('$') != std::string::npos || std::string{result}.find('_') != std::string::npos) {
        /// WRITE YOUR ALGO
        list_t *tmp = list;


    }
    std::cout << "The word was " << word << "." << std::endl;
    free(result);
    return (0);
}