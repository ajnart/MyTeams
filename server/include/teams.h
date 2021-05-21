/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: garuda]
** File description:
** teams
*/

#ifndef TEAMS_H_
#define TEAMS_H_

#include "definitions.h"

// When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid”
// “channel_uuid” “thread_uuid”): • /create [“comment_body”] : create a new
// reply
typedef struct comment {
    struct comment *next;
    uuid_t user_uuid;
    char *user_name;
    char *reply;
    time_t time;
} __attribute__((aligned(BITS))) comment;

// When team_uuid and channel_uuid are defined (/use “team_uuid”
// “channel_uuid”): • /create [“thread_title”] [“thread_message”] : create a
// new thread
typedef struct thread {
    struct thread *next;
    comment *comments;
    uuid_t uuid;
    char *name;
} __attribute__((aligned(BITS))) thread;

// When team_uuid is defined (/use “team_uuid”):
// • /create [“channel_name”] [“channel_description”] : create a new channel
typedef struct channel {
    struct channel *next;
    thread *threads;
    uuid_t uuid;
    char *name;
    char *description;
} __attribute__((aligned(BITS))) channel;

// When the context is not defined (/use):
// • /create [“team_name”] [“team_description”] : create a new team
typedef struct team {
    struct team *next;
    channel *channels;
    uuid_t uuid;
    char *name;
    char *description;
} __attribute__((aligned(BITS))) team;

#endif /* !TEAMS_H_ */
