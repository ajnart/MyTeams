/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: elitebook]
** File description:
** main
*/

#include "main.h"
#include "myteams/logging_client.h"

int main(int argc, char const *argv[])
{
    stop();
    client_event_logged_in("hello", "world");
    return 0;
}