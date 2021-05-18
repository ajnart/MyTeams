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
void help(void);

#endif /* !COMMANDS_H_ */
