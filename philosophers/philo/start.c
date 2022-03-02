/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:02:26 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 15:55:19 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	*routine(void *philo)
{
	t_philo	*philoc;
	t_para	*para;

	philoc = (t_philo *)philo;
	para = philoc->para;
	if (philoc->philo_id % 2)
		usleep(15000);
	while (!check_dead(philo) && !all_eat(para))
	{
		print_eat(philo);
		if (para->stop)
			return (NULL);
		print_action(philo, "is sleeping");
		if (para->stop)
			return (NULL);
		minisleep(para->sleep_t, philo);
		if (para->stop)
			return (NULL);
		print_action(philo, "is thinking");
		if (para->stop)
			return (NULL);
	}
	return (NULL);
}

int	start(t_para *para)
{
	int	i;

	i = 0;
	para->start = timer();
	para->stop = 0;
	while (++i <= para->nphilo)
	{
		para->philo[i].last_meal = para->start;
		if (pthread_create(&para->philo[i].p_id,
				NULL, &routine, &para->philo[i]) != 0)
		{
			printf("Error on thread creation\n");
			return (0);
		}
	}
	i = 1;
	while (i <= para->nphilo)
		pthread_join(para->philo[i++].p_id, NULL);
	mutexes_destroyer(para);
	return (0);
}
