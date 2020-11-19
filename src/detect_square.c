/*
** EPITECH PROJECT, 2018
** detect_square
** File description:
** detect square
*/

#include "my.h"

bool check_squares(char *buff, prop *map, int i, int size)
{
    int width = 0;
    int length = 0;

    for (int j = i; buff[j + length * (map->cols + 1)] &&
    buff[j + length * (map->cols + 1)] == '.';) {
        if (width == size && length == size)
            return (true);
        if (width == size && length < size) {
            length++;
            width = 0;
            j = i;
        }
        else {
            width++;
            j++;
        }
    }
    return (false);
}

char *modify_map(char *buff, int i, int size, prop *map)
{
    int width = 0;
    int length = 0;

    for (int origin = i; buff[i + length * (map->cols + 1)];) {
        buff[i + length * (map->cols + 1)] = 'x';
        if (width == size && length == size)
            return (buff);
        if (width == size && length < size) {
            length++;
            width = 0;
            i = origin;
        }
        else {
            width++;
            i++;
        }
    }
    return (buff);
}

char *detect_squares(char *buff, prop *map)
{
    int size_sq = 0;
    int locate = 0;

    for (int i = 0; buff[i];) {
        if (check_squares(buff, map, i, size_sq) == true) {
            size_sq++;
            locate = i;
        }
        else
            i++;
    }
    if (size_sq > 0)
        buff = modify_map(buff, locate, size_sq - 1, map);
    return (buff);
}
