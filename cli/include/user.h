/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** user
*/

#ifndef USER_H_
#define USER_H_

#include <stdbool.h>
#include <uuid/uuid.h>

typedef struct {
    bool connected;
    uuid_t uuid;
} user;

#endif /* !USER_H_ */
