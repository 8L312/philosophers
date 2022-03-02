/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:02:47 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 16:12:10 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo {
	pthread_t		p_id;
	int				philo_id;
	long			last_meal;
	char			status;
	long			act_s;
	int				pdead;
	int				pmeal;
	int				left;
	int				right;
	struct s_para	*para;
}	t_philo;

typedef struct s_para {
	long			start;
	long			timestamp;
	t_philo			philo[250];
	pthread_mutex_t	fork[250];
	pthread_mutex_t	lock;
	int				nphilo;
	int				eat_t;
	int				sleep_t;
	int				die_t;
	int				nmeal;
	int				stop;
}	t_para;

int		ft_atoi(const char *str);
void	minisleep(long action, t_philo *philo);
void	one_philo(t_para *para);
long	timer(void);
int		verifarg(char **argv);
int		isnum(char *str);
int		init(char **argv, t_para *para);
void	init_philo(t_para *para, int n);
int		init_mutexes(t_para *para);
int		start(t_para *para);
void	*routine(void *philo);
void	print_eat(t_philo *philo);
int		print_action(t_philo *philo, char *action);
int		all_eat(t_para *para);
int		check_dead(t_philo *philo);
void	mutexes_destroyer(t_para *para);

#endif
