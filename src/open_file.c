/*
** EPITECH PROJECT, 2018
** open_file
** File description:
** open_file
*/

#include "my.h"

void exit_program(char *buff, char *number)
{
    free(number);
    free(buff);
    exit(MY_EXIT_ERROR);
}

int analyse_nb_lines(char *buff, prop *map)
{
    int nb_lines = 0;
    int nb = 0;
    int i = 0;
    char *number = malloc(sizeof(char) * (map->cols + 1));

    for (i = 0; buff[i] && buff[i] != '\n'; i++)
        number[i] = buff[i];
    number[i] = 0;
    if ((nb_lines = my_getnbr(number)) <= 0)
        exit_program(buff, number);
    for (i = i + 1; buff[i]; i++) {
        if (buff[i] == '\n')
            nb++;
        if (nb == nb_lines && buff[i + 1] && buff[i + 1] != 0)
            exit_program(buff, number);
    }
    if (nb != nb_lines)
        exit_program(buff, number);
    display_one_line(buff, nb_lines);
    free(number);
}

int parse_map(char *buff, prop *map)
{
    int i = 0;

    map->cols = 0;
    for (; buff[i] && buff[i] != '\n'; i++)
        if (buff[i] < '0' || buff[i] > '9')
            exit(MY_EXIT_ERROR);
    i++;
    for (; buff[map->cols + i] && buff[map->cols + i] != '\n'; map->cols++)
        if (buff[map->cols + i] != '.' && buff[map->cols + i] != 'o')
            exit(MY_EXIT_ERROR);
    for (int j = map->cols + i + 1; buff[j]; j++) {
        if (buff[j] != '.' && buff[j] != 'o' && buff[j] != '\n')
            exit(MY_EXIT_ERROR);
        if (buff[j - map->cols - 1] == '\n' && buff[j] != '\n')
            exit(MY_EXIT_ERROR);
    }
    analyse_nb_lines(buff, map);
}

char *fill_buffer(int fd, struct stat info, char *buff, prop *map)
{
    buff = malloc(sizeof(char) * (info.st_size + 1));
    if (read(fd, buff, info.st_size) <= 0) {
        free(buff);
        exit(MY_EXIT_ERROR);
    }
    parse_map(buff, map);
    return (buff);
}

char *open_file(char *filepath, char *buff, prop *map)
{
    struct stat info;
    int fd = open(filepath, O_RDONLY);

    if (fd < 0)
        return (NULL);
    stat(filepath, &info);
    buff = fill_buffer(fd, info, buff, map);
    return (buff);
}
