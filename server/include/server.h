/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: garuda]
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "client.h"
#include "teams.h"

typedef struct server {
    clients *clients;
    team *teams;
} __attribute__((aligned(16))) server;

#endif /* !SERVER_H_ */
