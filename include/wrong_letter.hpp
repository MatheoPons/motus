/*
** EPITECH PROJECT, 2022
** motus
** File description:
** wrong_letter.hpp
*/

#ifndef MY_WLETTER_HPP_
    #define MY_WLETTER_HPP_

    typedef struct wletter_s
    {
        char wletter;
        struct wletter_s *next;
    } wletter_t;

#endif