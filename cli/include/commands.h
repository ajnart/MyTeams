/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "definitions.h"

// Gets the command, if any, contained in line.
enum commands getcommand(char *line);
// Prints the big help message
int help(connection_t __attribute__((unused)) *connection);
// login command
int login(connection_t *command);
// Logout
int logout(connection_t *command);

#endif /* !COMMANDS_H_ */
