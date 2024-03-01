/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:58:02 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 22:33:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define NEEDS_EAT 0
# define NEEDS_SLEEP 1
# define NEEDS_THINK 2
# define UNAVAL_FORK 0
# define AVAL_FORK 1

typedef struct s_philo
{
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_last_meal;
	int				philo_status;
	int				philo_total_meals;
	int				philo_num;
	int				fork;
	int				philo_forks;
	int				*end;
	int				*total_meals;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*end_m;
}	t_philo;

typedef struct s_args
{
	t_philo	*philo1;
	t_philo	*philo2;
}	t_args;

//Utils
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int i);
int		ft_atol(const char *str);

//Drop forks
void	drop_forks(t_philo *philo, t_philo *other);

//End
int		philo_end(t_philo *philos, pthread_t *threads, int nbr);

//Error
int		print_error(char *error);

//Free
void	ft_free(t_philo *philos, int nbr);

//Init
int		init_philos(t_philo *philos, char **av, int ac, int *end);
int		init_philos2(t_philo *philos, char **av);
void	init_ends(t_philo *philos, int *total_meals, pthread_mutex_t *end_m);
int		init_pinit_threadshilos(pthread_t *th, int nbr, t_philo *philos);

//Main
int		main(int argc, char **argv);

//Parsing
int		args_validate(int argc, char **argv);

//Print
void	philo_print(int time, char *message, t_philo *philo);

//Routine
void	*routine(void *philo);
void	philo_process(t_philo *philo, t_philo *other);

//Take forks
void	take_forks(t_philo *philo, t_philo *other);

//Time to
void	time_to_die(t_philo *philo);
void	time_to_eat(t_philo *philo, t_philo *other);
void	time_to_sleep(t_philo *philo);
void	time_to_think(t_philo *philo, t_philo *other);

//Time
int		ft_time(void);

//Total meals
void	philo_total_meals(t_philo *philo);

#endif