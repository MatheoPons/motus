/*
** EPITECH PROJECT, 2022
** motus
** File description:
** list.hpp
*/

typedef struct list_s
{
    char *word;
    struct list_s *next;
} list_t;

void create_list_from_dictionary(char const * const * const dictionary, size_t const dictionary_size, list_t *list, const size_t word_length);
void remove_at(size_t const idx, list_t *list);
void remove_wrong_answer(char const * const result, char const * const guess, size_t const word_length, list_t *list);
