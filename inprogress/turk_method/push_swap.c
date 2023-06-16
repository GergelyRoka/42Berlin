/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:05:31 by saimar            #+#    #+#             */
/*   Updated: 2023/06/16 01:13:48 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk_method/turk_method.h"

int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

//this one I put in checkers
// int check_digit(char *str)
// {
//     int i;
    
//     i = 0;
//     while(str[i])
//     {
//         if(str[i] == '-' || str[i] == '+')
//             i++;
//         if(str[i] >= '0' && str[i] <= '9')
//             return(1);
//         i++;
        
//     }
//     return(0);
// }

int main(int ac, char **av)
{
    int i;
    t_node *a;
    t_node *b;
    int *array;

    b = NULL;
    if(ac >= 2) // to double_check
    {
        i = 1;
        //check digits: ft_check_digits(char **av);
        while(av[i])
        {
            while(av[i])
            {
                if(check_digit(av[i]) == 0)
                {
                    write(1, "Error\n", 6);
                    return(0);
                }
                   
            i++;
            }
        }
    }
    else    
    {
        return(0);
    }
    //---TO DO: CHECK FOR DOUBLES
    i = 1;	
    while(av[i])
    {
	    if(check_duplicates(&av[i]) == 1)
        {
            write(1, "ERROR/n", 6);
    		return(0);
        }
    	i++;
    }
    i = 1;
    while(av[i])
    {
        if (INT_MIN > (long long)ft_atoi(av[i]) || INT_MAX < (long long)ft_atoi(av[i]))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        // printf("ft_atoi(av[i]) --> %lli\n", (long long)ft_atoi(av[i]));
        // printf("INT_MIN: %i\n", INT_MIN);
        // printf("INT_MAX: %i\n", INT_MAX);
        i++;
    }
    a = create_stack(av); // a points to the start of the first stack

    array = create_array(ac - 1, a);
    //array_three_biggest_number(ac - 1, array, a);

    //print_stack(a);
    turk_method(&a, &b);
    //print_stack(a);



    //ft_sort_big(&a, &b, array, ac - 1);

    // ft_sort_big(&a, &b, array, ac - 1);
    
    //print_array(array, ac - 1);
    
    
    

    //_10minutes_sort(&a, &b);

}

void print_stack(t_node *a)
{
    int i = 1;
    while (a)
    {
        printf("%i. %i\n", i, a->value);
        a = a->next;
        if(a->title == 'h')
            break;
        ++i;
    }
}

t_node	*create_node(int n) //newroll for Martin
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = n;
	new_node->next = NULL;
    new_node->prev = NULL;
    new_node->biggest = 0;
    //we will handle more errors
	return (new_node);
}

t_node *create_stack(char **av) // add at the end -- when you call this you need to know there is at least one av
{
	int		i;
	t_node	*new_node;
	t_node	*header;
	t_node	*curr;

	new_node = create_node(ft_atoi(av[1]));
	curr = new_node;
	curr->title = 'h';
	new_node->next = new_node;
	new_node->prev = new_node;
	header = curr;
	i = 2;
	while(av[i])
	{
		new_node = create_node(ft_atoi(av[i]));
		header->prev = new_node;
		new_node->next   = header;
		curr->next       = new_node;
		new_node->prev   = curr;
		curr             = new_node;
		curr->title = '\0';
		i++;
	}
	return(header);
}
