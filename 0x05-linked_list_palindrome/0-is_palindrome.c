#include "lists.h"

/**
 * is_palindrome- Determines if a linked list is palindrome or not
 * @head: pointer to list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *tmp = NULL;
    int len_list = 0, start = 0, end = 0;
    int *my_stack = NULL;

    if(!(*head))
        return 1;

    for(tmp = *head; tmp != NULL; tmp = tmp->next)
        len_list++;

    my_stack = malloc(sizeof(int) * len_list);

    for(tmp = *head; tmp != NULL; tmp = tmp->next)
        my_stack[end++] = tmp->n;

    while(start < end)
    {
        if(my_stack[start++] != my_stack[--end])
        {
            free(my_stack);
            return 0;
        }
    }

    free(my_stack);
    return 1;
}
