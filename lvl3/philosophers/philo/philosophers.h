/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:46:56 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/30 21:51:34 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define TOTAL_MEALS 4
# define FORK 5
# define MAX_PHILOS 200

typedef struct t_philo
{
	int					position;
	int					eats;
	unsigned long long	lifetime;
	unsigned long long	last_eat_time;
	int					left_fork;
	int					right_fork;
	int					eat_count;
	struct t_simulation	*simulation;
	pthread_mutex_t		action_mutex;
}	t_philo;

typedef struct t_simulation
{
	int					philosopher_count;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					eat_count;
	unsigned long long	start_time;
	t_philo				philosophers[MAX_PHILOS];
	pthread_mutex_t		forks[MAX_PHILOS];
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
}	t_simulation;

int					parse(char **argv);
int					init_struct(int argc, char **argv,
						t_simulation *simulation);
int					start_simulation(t_simulation *simulation);
int					init_philosophers(t_simulation *simulation,
						int philosopher_count);
void				*philosopher_routine(void *arg);
void				*monitor(void *arg);
void				*eat_monitor(void *arg);
void				eat(t_philo *philo);
void				write_message(t_philo *philo, int type);
unsigned long long	ft_time(void);
long				ft_atol(const char *str);
int					ft_atoi(const char *str);

#endif
