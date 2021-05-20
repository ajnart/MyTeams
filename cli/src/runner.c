/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** run
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "definitions.h"

// TODO: Add all functions corresponding to commands here
int (*pf[])(connection_t *connection, char *line) = {help, login, logout};

int run(connection_t *connection)
{
    char *line = (char *) malloc(BLOCK * sizeof(char));
    size_t block = BLOCK;
    int read = 0;

    while (true) {
        printf("❯ ");
        if ((read = getline(&line, &block, stdin) == -1))
            break;
        enum commands command = NONE;
        command = getcommand(line);
        if (command != NONE) {
            read = pf[command](connection, line);
            printf("[D]: Command returned %s\n", read == 0 ? "OK" : "ERROR");
        }
        else if (strcmp(line, "") == 0)
            printf("CLI: Command not found: %s", line);
        fflush(stdout);
    }
    close(connection->socket_fd); // Close socket connection.
    return (OK);
}