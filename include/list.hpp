/*
** EPITECH PROJECT, 2022
** motus
** File description:
** list.hpp
*/

#ifndef MY_LIST_HPP_
    #define MY_LIST_HPP_

    #include <cstddef>

    typedef struct list_s {
        char *word;
        struct list_s *next;
    } list_t;

    void create_list_from_dictionary(char const * const * const dictionary, size_t const dictionary_size, list_t *list, size_t const word_length);

#endif

