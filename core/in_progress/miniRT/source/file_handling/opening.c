/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:51:22 by groka             #+#    #+#             */
/*   Updated: 2024/03/20 18:37:51 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include <sys/stat.h>
# include <fcntl.h>

int	file_opening(const char *path);
int	file_closing(int fd);
int	reading_printing(int fd);
void	free_splitted_line(char **splitted_line);
int	set_element(char **splitted_line);
t_scene	*get_scene(void);


int	file_processing(const char *path)
{
	int	fd;

	fd = file_opening(path);
	if (fd == -1)
		return (-1);
		
	reading_printing(fd);
	if (file_closing(fd) == -1)
		return (-2);
	return (0);
}

int	reading_printing(int fd)
{
	char	*line;
	char 	**splitted_line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{

		// ft_putstr_fd(line, STDOUT_FILENO);
		// splitted_line = ft_split(line, ' ');
		// if (splitted_line)
		// {
		// 	// int i = 0;
		// 	// while(splitted_line[i])
		// 	// {
		// 	// 	ft_putstr_fd(splitted_line[i], STDOUT_FILENO);
		// 	// 	ft_putstr_fd(" ", STDOUT_FILENO);
		// 	// 	char *l = ft_itoa(ft_strlen(splitted_line[i]));
		// 	// 	ft_putendl_fd(l, STDOUT_FILENO);
		// 	// 	free(l);

		// 	// 	i++;
		// 	// }
		// 	// i = 0;
		// 	// while (splitted_line[i])
		// 	// {
		// 	// 	free(splitted_line[i]);
		// 	// 	++i;
		// 	// }
		// 	// free(splitted_line);
		// }
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	processing_line(char *line)
{
	char **splitted_line;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (-13);
	if (set_element(splitted_line))
	{
		free_splitted_line(splitted_line);
		return 1;
	}
	free_splitted_line(splitted_line);
	return (0);
}

int	set_element(char **splitted_line)
{
	if (ft_strcmp(splitted_line[0], "\n"))
		return (0);
	if (ft_strcmp(splitted_line[0], "A") == 0) // splitted_line[0] 
		return (set_ambient_from_line(splitted_line));
	else if(ft_strcmp(splitted_line[0], "C") == 0)
		return (set_camera_from_line(splitted_line));
	else if(ft_strcmp(splitted_line[0], "L") == 0)
		return (set_light_from_line(splitted_line));
	else if(ft_strcmp(splitted_line[0], "pl") == 0)
		return (set_plane_from_line(splitted_line));
	else if(ft_strcmp(splitted_line[0], "sp") == 0)
		return (set_sphere_from_line(splitted_line));
	else if(ft_strcmp(splitted_line[0], "cy") == 0)
		return (set_cylinder_from_line(splitted_line));
	return (-1);
}

int	set_ambient_from_line(char **splitted_line)
{
	if (get)
	return (0);
}

void	free_splitted_line(char **splitted_line)
{
	int i;

	i = 0;
	while (splitted_line[i])
	{
		free(splitted_line[i]);
		++i;
	}
	free(splitted_line);
}

int	file_closing(int fd)
{
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int	file_opening(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

