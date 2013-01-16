#include "list.h"

#include <stdio.h>
#include <assert.h>

int
main()
{
	int test = 8;
	
	//list_init
	list_t *list = list_init(6, test);

	//list_print
	list_print(list);

	//list_length
	assert(list_length(list) == 6);

	//list_push_back
	list_push_back(list, test);
	list_print(list);
	assert(list_length(list) == 7);

	//list_pop_back
	list_pop_back(list);
	list_print(list);
	assert(list_length(list) == 6);

	return 0;
}
