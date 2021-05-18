/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** help
*/

#include <stdio.h>
#include <unistd.h>
#include "commands.h"

int help(connection_t __attribute__((unused)) *connection)
{
    printf(
        "•/help:\t show help\n"
        "•/login\t [\"user_name\"] : set the user_name used by client\n"
        "•/logout:\t disconnect the client from the server\n"
        "•/users:\t get the list of all users that exist on the domain\n"
        "•/user\t [\"user_uuid\"] : get information about a user\n"
        "•/send\t [\"user_uuid\"] [\"message_body\"] : send a message to a user\n"
        "•/messages\t [\"user_uuid\"] : list all messages exchange with an user\n"
        "•/subscribe\t [\"team_uuid\"] : subscribe to the event of a team and "
        "its sub directories (enable reception of all events from a team)\n"
        "•/subscribed\t ?[\"team_uuid\"] : list all subscribed teams or list all "
        "users subscribed to a team\n"
        "•/unsubscribe\t [\"team_uuid\"] : unsubscribe from a team\n"
        "•/use\t ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : use "
        "specify a context team/channel/thread\n"
        "•/create:\t based on what is being used create the sub resource (see "
        "documentation)\n"
        "•/list:\t based on what is being used list all the sub resources"
        "(see documentation)\n"
        "•/info:\t based on what is being used list the current (see "
        "documentation)\n");
    return (OK);
}