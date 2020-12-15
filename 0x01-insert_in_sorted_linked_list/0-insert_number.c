#include "lists.h"

/**
 * insert_node - Inserts a node in a singly linked list
 * @head: Pointer to pointer to head of list
 * @number: The number to insert
 * Return: The address of the inserted node
 * By: Software engineer Eduardo A. Vega
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *aux_fast = NULL, *aux_slow = NULL, *new_node = NULL;

    if(head == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if(new_node == NULL)
	    return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    if ((*head)->n > number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    aux_slow = *head;
    for (aux_fast = (*head)->next; aux_fast != NULL; aux_fast = aux_fast->next)
    {
        if (aux_fast->n > number)
        {
            aux_slow->next = new_node;
            new_node->next = aux_fast;
            return new_node;
        }
        aux_slow = aux_fast;
    }

    new_node = add_nodeint_end(head, (const int)number);
    return (new_node);
}