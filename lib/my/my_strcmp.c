/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int max1 = 0;
    int max2 = 0;

    while (s1[max1] != '\0')
        max1++;
    while (s2[max2] != '\0')
        max2++;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if (i == max1 && i == max2)
        return (0);
    else if (i == max1 && i < max2)
        return (-1);
    else
        return (1);
}
