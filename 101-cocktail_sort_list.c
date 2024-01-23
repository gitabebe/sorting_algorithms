#include "sort.h"

/**
 *swap - swaps 2 nodes in a doubly-linked list
 *@first: address of first node
 *@second: address of second node
 *Return: Nothing
 */
void swap(listint_t *first, listint_t *second)
{
	if (first->prev)
	first->prev->next = second;
	if (second->next)
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}

/**
 *backSort- function that sorts from the back
 *@head: head of list
 *@tail: tail of the list
 *@list: head of the list
 *Return: new head of the list
 */
listint_t *backSort(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 *cocktail_sort_list - sorts linked list using cocktail shaker sort
 *
 *@list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *len;
	int i = 0, j = 0, swaped = 1;

	if (!list || !*list)
		return;
	len = *list;
	for (i = 0; len; i++)
		len = len->next;
	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		swaped = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap(head, head->next);
				swaped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = backSort(head, tail, *list);
		*list = head;
		j++;
	}
}
