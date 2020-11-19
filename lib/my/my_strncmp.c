/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** compare n bytes of two strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int max1 = 0;
    int max2 = 0;

    while (s1[max1] != '\0')
        max1++;
    while (s2[max2] != '\0')
        max2++;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
        i++;
    if (i == n && max1 == max2)
        return (0);
    else if (i < n && max1 <= max2)
        return (-1);
    else
        return (1);
}
