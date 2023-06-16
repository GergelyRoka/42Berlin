#include "push_swap.h"



void bubble_sort(int *array, int size)
{
	int     i;
	int     flag;
	int     tmp;

	flag = 1;
	while(flag)
	{
		i = 0;
		flag = 0;
		while(i + 1 < size)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				flag = 1;
			}
			++i; 
		}
	}
}

int *create_array(int size, t_node *stack)
{
	int *array;
	int i;

	i = 0;
	array = malloc(size * sizeof(int));
	array[i] = stack->value;
	stack = stack->next;
	while(stack->title != 'h')
	{
		++i;
		array[i] = stack->value;
		stack = stack->next;
	}
	bubble_sort(array, size);
	return (array);
}
void print_array(int *array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%i) %i\n", i, array[i]);
        ++i;
    }
}

void array_three_biggest_number(int size, int *array, t_node *stack)
{
	if (stack == NULL)
		return ;
	if (stack->value >= array[size - 5])
		stack->biggest = 1;
	stack = stack->next;
	while(stack->title != 'h')
	{
		if (stack->value >= array[size - 5])
			stack->biggest = 1;
		stack = stack->next;
	}
}