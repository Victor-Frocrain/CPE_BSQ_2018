/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0; str[i]; i++)
        result[i] = str[i];
    return (result);
}
