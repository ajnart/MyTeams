/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** help
*/

#include <stdio.h>
#include <unistd.h>
#include "commands.h"

void help(void)
{
    printf(
        "•\t/help : show help\n"
        "•\t/login [\"user_name\"] : set the user_name used by client\n"
        "•\t/logout : disconnect the client from the server\n"
        "•\t/users : get the list of all users that exist on the domain\n"
        "•\t/user [\"user_uuid\"] : get information about a user\n"
        "•\t/send [\"user_uuid\"] [\"message_body\"] : send a message to a user\n"
        "•\t/messages [\"user_uuid\"] : list all messages exchange with an user\n"
        "•\t/subscribe [\"team_uuid\"] : subscribe to the event of a team and "
        "its sub directories (enable reception of all events from a team)\n"
        "•\t/subscribed ?[\"team_uuid\"] : list all subscribed teams or list all "
        "users subscribed to a team\n"
        "•\t/unsubscribe [\"team_uuid\"] : unsubscribe from a team\n"
        "•\t/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : use "
        "specify a context team/channel/thread\n"
        "•\t/create : based on what is being used create the sub resource (see "
        "documentation)\n"
        "•\t/list : based on what is being used list all the sub resources"
        "(see documentation)\n"
        "•\t/info : based on what is being used list the current (see "
        "documentation)\n");
}