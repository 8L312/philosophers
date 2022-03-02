/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:24:59 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 15:54:05 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	print_eat(t_philo *philo)
{
	t_para	*para;

	para = philo->para;
	if (!para->stop)
	{
		pthread_mutex_lock(&para->fork[philo->left]);
		pthread_mutex_lock(&para->fork[philo->right]);
		print_action(philo, "has taken a fork");
		print_action(philo, "has taken a fork");
		print_action(philo, "is eating");
		philo->pmeal++;
		minisleep(para->eat_t, philo);
		philo->last_meal = timer();
		pthread_mutex_unlock(&para->fork[philo->left]);
		pthread_mutex_unlock(&para->fork[philo->right]);
	}
}

int	print_action(t_philo *philo, char *action)
{
	long	laps;
	t_para	*para;

	para = philo->para;
	if (!para->stop)
	{
		laps = timer() - para->start;
		pthread_mutex_lock(&para->lock);
		if (para->stop)
		{
			pthread_mutex_unlock(&para->lock);
			return (0);
		}
		printf("%ld : %d %s\n", laps, philo->philo_id, action);
		if (action[0] == 'd')
		{
			para->stop = 1;
			usleep(100);
		}
		pthread_mutex_unlock(&para->lock);
	}
	return (0);
}
