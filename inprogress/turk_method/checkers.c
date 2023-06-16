#include "push_swap.h"
 
	 
int	ft_check_digits(char **av)
{
	int i;
	
	i = 1;	 
 	while(av[i])
  	{
		if(check_digit(av[i]) == 0)
		{
			write(1, "Error\n", 6);
			return(0);
		}
	i++;
	}
	return (1);
}

int	check_digit(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '-' || str[i] == '+')
            i++;
    	if(str[i] >= '0' && str[i] <= '9')
            return(1);    
        i++;
        
    }
    return(0);
}

/*int	check_duplicates(char **av)
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
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
*/
