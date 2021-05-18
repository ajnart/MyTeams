/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** run
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "commands.h"
#include "definitions.h"

int run(connection_t *connection)
{
    char *line = NULL;
    size_t block = BLOCK;

    line = (char *) malloc(block * sizeof(char));
    if (line == NULL) {
        perror("Unable to allocate buffer");
        return (ERROR);
    }
    while (getline(&line, &block, stdin)) {
#ifdef __DEBUG
        printf("[D] You entered: %s\n", line);
#endif
        enum commands command = NONE;
        command = getcommand(line);
        switch (command) {
            case HELP: help();
            default: break;
        }
    }
    close(connection->socket_fd); // Close socket connection.
    return (OK);
}