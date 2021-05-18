/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** run
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "commands.h"
#include "definitions.h"

// TODO: Add all functions corresponding to commands here
const int (*pf[])(connection_t *connection) = {help, login, logout};

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
        enum commands command = NONE;
        command = getcommand(line);
#ifdef __DEBUG
        printf("[D] You entered: %s\nLaunching command: %d\n", line, command);
#endif
        if (command != NONE) {
            pf[command](connection);
        }
    }
    close(connection->socket_fd); // Close socket connection.
    return (OK);
}