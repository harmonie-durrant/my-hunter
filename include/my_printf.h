/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    int my_printf(const char *format, ...);

    int	my_putstr(char const *str);

    void my_putchar(char c);

    int	my_strlen(char const *str);

    int my_put_nbr(int nb);

    int my_compute_power_rec(int nb, int p);

    int my_put_flt(double nbr, int j, int *counter);

    int my_put_flt_g(double nbr, int j, int *counter);

    void print_flt(long decimal, int j, long temp, int *counter);

    char *my_strcpy(char *dest, char const *src);

    char *my_strcat(char *a, char *b);

    char *convert(unsigned int num, int base, int cap);

    int flag_x(const char *format, int i, va_list args, int *counter);

    int flag_f(const char *format, int i, va_list args, int *counter);

    int flag_g(const char *format, int i, va_list args, int *counter);

    int flag_a(const char *format, int i, va_list args, int *counter);

    int flag_biga(const char *format, int i, va_list args, int *counter);

    int flag_c(const char *format, int i, va_list args, int *counter);

    int flag_c(const char *format, int i, va_list args, int *counter);

    int flag_s(const char *format, int i, va_list args, int *counter);

    int flag_p(const char *format, int i, va_list args, int *counter);

    int flag_n(const char *format, int i, va_list args, int *counter);

    int flag_b(const char *format, int i, va_list args, int *counter);

    void flag_bigs(char *str, int *count);

    int flag_di(const char *format, int i, va_list args, int *counter);

    int flag_u(const char *format, int i, va_list args, int *counter);

    int flag_o(const char *format, int i, va_list args, int *counter);

    int flag_e(const char *format, int i, va_list args, int *counter);

    int flag_g(const char *format, int i, va_list args, int *count);

    void my_put_sci(double num, int cap, int prec, int *count);

    int reducenum(int num, int *i);

    void my_put_sci_neg(double num, int cap, int prec, int *count);

    int count_char_nbr(int nbr);

    int count_char_uns(unsigned int nbr);

    int my_atoi(char *str);

#endif /* MY_PRINTF_H_ */
