#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list_t*
list_init(int count, type data)
{	
    list_t *list = malloc(sizeof(list_t));
	if (list == NULL)
		return NULL;

	list->count = 0;
	list->tail = list->head = NULL;
	int i;
	for (i = 0; i < count; ++i)
	{
		list_push_back(list, data);
	}

	return list;
}

void
list_push_back(list_t *list, type data)
{
	node_t *node = malloc(sizeof(node_t));
	if (node == NULL)
		return;
	
	node->data = data;
	if (list->head == NULL)
	{
		list->head = node;
		list->head->next = list->head->prev = node;
		list->tail = node;
		list->tail->next = list->tail->prev = node;
	}
	else
	{
		list->tail->next = node;
		node->next = list->head;
		node->prev = list->tail;
		list->head->prev = node;
	}
	list->count++;
}

void
list_pop_back(list_t *list)
{
	if (list == NULL || list->count == 0)
		return;
	
	node_t *next = list->head->next;
	next->prev = list->tail->prev;
	list->tail->prev = next->prev;
	list->count--;
	if (list->head == NULL)
		free(list->head);
}

void
list_print(list_t *list)
{
	node_t *node = list->head;
	int i;
	for (i = 0; i < list->count; ++i)
	{
		printf("%d", node->data);
		node = node->next;
	}
	printf("\n");
}

int
list_length(list_t *list)
{
	return list->count;
}

