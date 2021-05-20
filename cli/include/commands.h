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
enum commands getcommand(const char *line);
// Prints the big help message
int help(connection_t *connection, char *str);
// login command
int login(connection_t *command, char *str);
// Logout
int logout(connection_t *command, char *str);
int user(connection_t *command, char *str);
int users(connection_t *command, char *str);
#endif /* !COMMANDS_H_ */
