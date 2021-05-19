/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** str_to_word_array
*/

#include "teams_server.h"

char **str_to_word_array(char *str, char *delim)
{
    char *ptr = strtok(str, delim);
    int i = 0;
    char **array = malloc(sizeof(char *) * i);

    while(ptr != NULL) {
        array[i] = strdup(ptr);
        printf("%s\n", array[i]);
        ptr = strtok(NULL, delim);
        i++;
    }
    array[i] = NULL;
    return array;
}