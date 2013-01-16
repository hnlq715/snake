#ifndef __list_h__
#define __list_h__

typedef int type;

typedef struct node{
	type data;
	struct node *prev;
	struct node *next;
}node_t;

typedef struct list{
	int count;
	node_t *head;
	node_t *tail;
}list_t;

list_t *list_init(int count, type data);

void list_push_back(list_t *list, type data);
void list_pop_back(list_t *list);
void list_print(list_t *list);

int list_length(list_t *list);


#endif
