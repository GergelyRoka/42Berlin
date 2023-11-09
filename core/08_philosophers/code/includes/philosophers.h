/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:55:26 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:37:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// memset
# include <string.h>
// printf
# include <stdio.h>
// malloc
# include <stdlib.h>
// free
# include <stdlib.h>
// write
// usleep
# include <unistd.h>
// gettimeofday
# include <sys/time.h>
// pthread_create | pthread_detach | pthread_join
// pthread_mutex_init | pthread_mutex_destroy 
// pthread_mutex_lock | pthread_mutex_unlock
# include <pthread.h>
// bool
# include <stdbool.h>

typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

typedef struct s_data
{
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					full_meals;
	struct timeval		start_time;
	t_philo				*array_of_philos;
	t_fork				*array_of_forks;
	pthread_t			*threads;
	pthread_mutex_t		write_mutex;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					full_meals;
	struct timeval		start_time;
	struct timeval		meal_time;
	int					last_meal;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_mutex_t		*write_mutex;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t		mutex;
	bool				is_free;
}	t_fork;

enum	e_activities
{
	thinking,
	forking,
	eating,
	sleeping,
	dying,
	none,
	waiting,
	trying
};

//ARGUMENTUM
int			argumentum(int ac, char **av, t_data *data);

//CREATES_N_FREES
int			creation(t_data *data);
int			create_forks(t_data *data);
int			create_philosophers(t_data *data);
int			create_threads(t_data *data);
int			free_everything(t_data *data);
int			free_forks(t_data *data);
int			free_philosophers(t_data *data);
int			free_threads(t_data *data);
int			release_the_beasts(t_data *data);

// PHILOSPHER
void		*life_of_philosopher(void *attr);
int			do_think(t_philo *philosopher);
int			do_eat(t_philo *philosopher);
int			do_sleep(t_philo *philosopher);

//PTRINTING
int			number_of_philo(int num);
int			do_print(t_philo *philo, int activity, int finished);

// timing

int			timing(t_philo *philo, int activity);
int			progress_time(t_philo *philo);

#endif