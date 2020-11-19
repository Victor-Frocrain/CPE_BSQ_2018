/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    prop *map = malloc(sizeof(prop));
    char *buff;

    if (ac != 2)
        return (MY_EXIT_ERROR);
    if ((buff = open_file(av[1], buff, map)) == NULL)
        return (MY_EXIT_ERROR);
    buff = detect_squares(buff, map);
    display_map(buff);
    free(buff);
    return (MY_EXIT_SUCCESS);
}
