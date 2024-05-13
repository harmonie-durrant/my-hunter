/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_STRUCT_H_
    #define MY_PRINTF_STRUCT_H_

    struct pro_cases {
        char flag;
        int (*ptr)(const char *, int, va_list, int *);
    };

#endif /* MY_PRINTF_STRUCT_H_ */
