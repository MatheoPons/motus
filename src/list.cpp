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

static void remove_first(list_t *list)
{
    list_t *to_free = list;
    list = list->next;
    free(to_free);
}

void remove_at(size_t const idx, list_t *list)
{
    list_t *tmp = list;
    size_t tmp_idx = 0;
    list_t *to_free = NULL;

    if (idx == 0) {
        remove_first(list);
        return;
    }
    while (tmp->next != NULL && tmp_idx < idx) {
        if (idx == tmp_idx + 1) {
            to_free = tmp->next;
            tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
        tmp_idx = tmp_idx + 1;
    }
    if (to_free != NULL)
        free(to_free);
}

void remove_wrong_answer(char const * const result, char const * const guess, size_t const word_length, list_t *list)
{
    list_t *tmp = list;
    size_t idx = 0;
    size_t tmp_idx = 0;

    while (tmp->next != NULL) {
        while (idx < word_length) {
            if (result[idx] == '$' && guess[idx] != tmp->word[idx]) {
                remove_at(tmp_idx, list);
                idx = word_length;
            }
            idx = idx + 1;
        }
        tmp_idx = tmp_idx + 1;
        tmp = tmp->next;
    }
}