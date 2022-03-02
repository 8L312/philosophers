/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:17:49 by rmonney           #+#    #+#             */
/*   Updated: 2022/02/24 16:54:35 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

long	timer(void)
{
	struct timeval	t;
	long			timelaps;

	gettimeofday(&t, NULL);
	timelaps = (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (timelaps);
}

void	minisleep(long action, t_philo *philo)
{
	long	start;

	start = timer();
	while (1)
	{
		if (check_dead(philo))
			break ;
		if ((timer() - start) >= action)
			break ;
		usleep(50);
	}
}

int	check_dead(t_philo *philo)
{
	t_para	*para;

	para = philo->para;
	if ((timer() - philo->last_meal) > para->die_t - 1)
	{
		if (!para->stop)
			print_action(philo, "died");
		return (1);
	}
	return (0);
}

void	mutexes_destroyer(t_para *para)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&para->lock);
	while (++i <= para->nphilo)
		pthread_mutex_destroy(&para->fork[i]);
}

int	all_eat(t_para *para)
{
	int	i;

	i = 1;
	if (para->nmeal == -1)
		return (0);
	while (i <= para->nphilo)
	{
		if (para->philo[i].pmeal < para->nmeal)
			return (0);
		else
			i++;
	}
	para->stop = 1;
	return (1);
}
