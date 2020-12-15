#include "lists.h"

/**
 * insert_node - Inserts a node in a singly linked list
 * @head: Pointer to pointer to head of list
 * @number: The number to insert
 * Return: The address of the inserted node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *aux_fast = NULL;
    listint_t *aux_slow = NULL;
    listint_t *new_node = NULL;

    /* If head is null */
    if(head == NULL || *head == NULL)    
        return NULL;
    
    /* Dynamically create the new node */
    new_node = malloc(sizeof(listint_t));
    new_node->n = number;
    new_node->next = NULL;

    /* First case: Number to insert is < or = head */
    if((*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    /* Second case: Number to insert >= head */    
    aux_slow = *head;
    for(aux_fast = *head; aux_fast != NULL; aux_fast = aux_fast->next)
    {
        if(aux_fast->n > number)
        {
            aux_slow->next = new_node;
            new_node->next = aux_fast;            
            return new_node;
        }        
        aux_slow = aux_fast;
    }

    /* Third case: Number to insert is greater than last number */
    new_node = add_nodeint_end(head, (const int)number);
    return new_node;
}