/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** count_num
*/

int count_char_nbr(int nbr)
{
    int count = 0;

    if (nbr < 0) {
        count += 1;
        count *= (-1);
    }
    while (nbr != 0) {
        nbr = nbr / 10;
        count += 1;
    }
    return count;
}

int count_char_uns(unsigned int nbr)
{
    int count = 0;

    while (nbr != 0) {
        nbr = nbr / 10;
        count += 1;
    }
    return count;
}
