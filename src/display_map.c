/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** display map
*/

#include "my.h"

void display_one_line(char *buff, int nb)
{
    bool box = false;

    for (int i = 2; nb == 1 && buff[i]; i++) {
        if (buff[i] == '.' && box == false) {
            my_putchar('x');
            box = true;
        }
        else
            my_putchar(buff[i]);
        if (buff[i] == '\n')
            exit(MY_EXIT_SUCCESS);
    }
}

void display_map(char *buff)
{
    int	i = 0;

    for	(; buff[i] && buff[i] != '\n'; i++);
    my_putstr(buff + i + 1);
}
