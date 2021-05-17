/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** test
*/

#include <gtest/gtest.h>
#include "argparser.h"

TEST(Main, helptest)
{
    int argc = 2;
    char *argv[] = {(char *) "myteams_cli", (char *)"-help"};
    ASSERT_EQ(checkargs(argc, argv), 0);
}

TEST(Main, second)
{
    ASSERT_EQ(0, 0);
}