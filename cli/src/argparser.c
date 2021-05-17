/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** argparser
*/

#include "argparser.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "definitions.h"

// 192.169.0.0.1
// 3-3-3-3-3-3 = 15 + 4 = 19
//TODO: Finish this. Catch args and allocate memory accordingly
struct connection parse_args(const char **argv)
{
    struct connection ret;
    ret.ip = argv[1];
    ret.port = strtol(argv[2], NULL , 10);
    #ifdef __DEBUG
    printf("[D]\tIP:%s\tPort:%d\n", ret.port);
    #endif
    return (ret);
}