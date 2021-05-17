/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** argparser
*/

#include "argparser.h"
#include <string.h>
#include <unistd.h>
#include "definitions.h"

// 192.169.0.0.1
// 3-3-3-3-3-3 = 15 + 4 = 19
//TODO: Finish this. Catch args and allocate memory accordingly
struct connection parse_args(const char **argv)
{
    struct connection ret = {.errno = 0};
    if (strlen(argv[1]) < 9)
        ret.errno = ERROR;
    return (ret);
    ret.ip = malloc(1 * strlen(argv[1]));
    ret.errno = 1;
    return (ret);
}