#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle
 * @list: Poiter to head of the linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow_ptr = list, *fast_ptr = list;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;

        if (fast_ptr == slow_ptr)
            return (1);

        slow_ptr = slow_ptr->next;
    }

    return (0);
}
