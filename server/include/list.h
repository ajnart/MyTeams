/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#include <sys/socket.h>
#include <sys/select.h>

typedef struct list
{
    int sockfd;
    bool is_authenticated;
    struct list *next;
    struct list *prev;
} list_t;

void add_client(list_t **list, int fd);
void delete_client(list_t **list, int fd, fd_set *__readfds);
list_t *get_current_client(list_t **list, int fd);
void print_client(list_t *list);


#endif /* !LIST_H_ */
