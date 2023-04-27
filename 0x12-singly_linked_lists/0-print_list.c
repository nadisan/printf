#include "lists.h"
#include <stdlib.h>

/**
 * print_list - prints all the elements of a list_t
 * @h: pointer to head of list
 *
 * Return: size_t
 */

size_t print_list(const list_t *h)
{
	int i = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[%i] %s\n", h->len, "(nil)");
		else
			printf("[%i] %s\n", h->len, h->str);
		h = h->next;
		i++;
	}
		return (i);
}
