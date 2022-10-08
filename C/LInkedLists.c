#include <stdio.h>
#include <stdlib>
#include <string.h>

/* 
An awesome linked lists implementation in C
Made by: IsaacNewTom
*/


/* whether we want debugging or not */
#define DEBUG 1

/* linked lists */
typedef struct linked_list {
    char *data;
    struct linked_list *next;
}list;

list *files_to_hide = NULL;
list *pids_to_hide = NULL;

/* Adds a node to the linked list */
int is_node_in_list(list **linked_list, char *data_to_check)
{
    list *list_ptr;
    list_ptr = *linked_list;
    while (list_ptr != NULL) {
        if (strlen(list_ptr->data) == strlen(data_to_check)){
            if (strncmp(data_to_check, list_ptr->data, strlen(list_ptr->data)) == 0){
                if (DEBUG)
                    printf("node: %s found in the list!\n", data_to_check);
                return 1;
            }
        }
        list_ptr = list_ptr->next;
    }
    return 0;
}

/* adds a node to the linked list*/
void add_node_to_list(list **linked_list, char *data_to_add)
{
    list *list_ptr;
    char *str;

    if (is_node_in_list(linked_list, data_to_add)){
                if (DEBUG)
                    printf("file: '%s' already in the list\n");
    }

    if (*linked_list == NULL) {
        list_ptr = (list*)malloc(sizeof(list));
        str = malloc(sizeof(*data_to_add));

        strncpy(str, data_to_add, sizeof(data_to_add));
        list_ptr->data = str;
        list_ptr->next = *linked_list;
        *linked_list = list_ptr;
        if (DEBUG)
            printf("node: %s added to the list!\n", data_to_add);
    } 

    else {
        list_ptr = *linked_list;
        while (list_ptr != NULL && (strlen(list_ptr->data) != strlen(data_to_add) || strncmp(list_ptr->data, data_to_add, strlen(list_ptr->data)) != 0)) 
        {
            list_ptr = list_ptr->next;
        }

        if (list_ptr == NULL) {
            list *ptr;
            ptr = (list*)malloc(sizeof(list));
            str = malloc(sizeof(*data_to_add));
            strcpy(str, data_to_add);
            ptr->data = str;
            ptr->next = *linked_list;
            *linked_list = ptr;
            if (DEBUG)
                printf("node: %s added to the list!\n", data_to_add);
        }
    }
}

/* removes a node from the linked list*/
void remove_node_from_list(list **linked_list, char *data_to_remove)
{
    if (!is_node_in_list(linked_list, data_to_remove)){
        if (DEBUG)
            printf("file: '%s' is not in the list, didn't remove it!\n", data_to_remove);
        return;
    }

    list *list_ptr, *ptr;
    int i = 0;
    list_ptr = *linked_list;
    while (list_ptr != NULL) {
        if (strlen(list_ptr->data) == strlen(data_to_remove)){
            if (strncmp(list_ptr->data, data_to_remove, strlen(list_ptr->data)) == 0) {
                if (i == 0) {
                    *linked_list = list_ptr->next;
                    free(list_ptr->data);
                    free(list_ptr);
                    if (DEBUG)
                        printf("node: '%s' removed from list\n", data_to_remove);
                    return;
                }
                ptr->next = list_ptr->next;
                free(list_ptr->data);
                free(list_ptr);
                if (DEBUG)
                    printf("node: '%s' removed from list\n", data_to_remove);
                return;
            }
        }
        ptr = list_ptr;
        list_ptr = list_ptr->next;
        i++;
    }
}

/* deallocate a linked list */
void clear_list(list **linked_list)
{
    list *list_ptr;
    list_ptr = *linked_list;
    while (list_ptr != NULL) {
        *linked_list = list_ptr->next;
        free(list_ptr->data);
        free(list_ptr);
        list_ptr = *linked_list;
    }

    if (DEBUG)
        printf("List freed!\n");
}

/* prints out a linked list's data */
void print_list(list **linked_list)
{
    if (DEBUG){
        list *list_ptr;
        list_ptr = *linked_list;
        while (list_ptr != NULL) {
            printf("current node: %s\n-->next_node's addr: %x\n\n", list_ptr->data, list_ptr->next);
            list_ptr = list_ptr->next;
        }
    }
}

/* prints out a linked list in a linked list format */
void print_list_format(list **linked_list)
{
    if (DEBUG){
        list *list_ptr;
        list_ptr = *linked_list;
        while (list_ptr != NULL) {
            printf("(%s)\n\t|\n\tv\n\t",list_ptr->data);
            list_ptr = list_ptr->next;
        }
    printf("\n");
    }
}
