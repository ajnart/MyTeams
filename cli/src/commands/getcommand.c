/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** getcommand
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "definitions.h"

// Todo : Add all the commands to the commands[] array.
// Note: No need to updated the for loop becuase sizeof(char *) = 8 so it knows when to stop looping
enum commands getcommand(const char *line)
{
    enum commands result = NONE;
    const char *commands[] = {"help", "login", "logout"};
    char *rest = strdup(line);

    if (line == NULL || line[0] != '/')
        return result;
    const char *cmd = strtok_r(rest, " \n", &rest);
    for (unsigned long i = 0; i < sizeof(commands)/8; i++)
    {
        if (strcmp(cmd+1, commands[i]) == 0)
            result = i;// I is set to the index of the command needed
    }
    return result; // If nothing is found it will return NONE
}