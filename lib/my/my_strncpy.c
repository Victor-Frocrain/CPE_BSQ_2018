/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copy n characters
*/

int my_count_char(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int max = my_count_char(src);

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > max)
        dest[i] = '\0';
    return (dest);
}
