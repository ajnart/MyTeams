/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list
{
    int sockfd;
    struct list *next;
    struct list *prev;
} list_t;

void add_client(list_t **list, int fd);
void delete_client(list_t **list, int fd, fd_set *__readfds);


#endif /* !LIST_H_ */
