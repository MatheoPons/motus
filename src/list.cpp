/*
** EPITECH PROJECT, 2022
** motus
** File description:
** list.cpp
*/

#include <cstring>
#include <cstddef>
#include <memory>
#include <iostream>

#include "list.hpp"

void create_list_from_dictionary(char const * const * const dictionary, size_t const dictionary_size, list_t *list, size_t const word_length)
{
    size_t idx = 0;
    list_t *tmp = list;

    while (idx < dictionary_size) {
        if (strlen(dictionary[idx]) == word_length) {
            tmp->word = (char *)malloc(sizeof(char) * strlen(dictionary[idx]));
            strcpy(tmp->word, dictionary[idx]);
            tmp->next = (list_t *)malloc(sizeof(list_t));
            tmp = tmp->next;
            tmp->word = NULL;
            tmp->next = NULL;
        }
        idx = idx + 1;
    }
}