#include "lists.h"

/**
 * insert_node - Insert node into a sorted singly listed link
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = NULL, *fast = *head, *slow = *head;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    while (fast != NULL)
    {
        if (fast->n >= number)
        {
            new_node->next = fast;

            if (fast == *head)
            {
                *head = new_node;
                return (new_node);
            }

            slow->next = new_node;
            return (new_node);
        }

        slow = fast;
        fast = fast->next;
    }

    slow->next = new_node;
    return (new_node);
}
