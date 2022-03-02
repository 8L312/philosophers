/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:42:32 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 15:44:08 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	init(char **argv, t_para *para)
{
	int	n;

	para->nphilo = ft_atoi(argv[1]);
	para->die_t = ft_atoi(argv[2]);
	para->eat_t = ft_atoi(argv[3]);
	para->sleep_t = ft_atoi(argv[4]);
	para->nmeal = -1;
	if (argv[5])
		para->nmeal = ft_atoi(argv[5]);
	if (!init_mutexes(para))
	{
		printf("Error on mutex creation\n");
		return (0);
	}
	n = 0;
	while (++n <= para->nphilo)
		init_philo(para, n);
	return (1);
}

void	init_philo(t_para *para, int n)
{
	para->philo[n].philo_id = n;
	para->philo[n].pdead = 0;
	para->philo[n].pmeal = 0;
	para->philo[n].status = 't';
	para->philo[n].para = para;
	para->philo[n].left = n + 1;
	para->philo[n].right = n;
	if (n == para->nphilo)
		para->philo[n].left = 1;
}

int	init_mutexes(t_para *para)
{
	int	i;
	int	ret;

	if (pthread_mutex_init(&para->lock, NULL) != 0)
		return (0);
	i = 0;
	while (++i <= para->nphilo)
	{
		ret = pthread_mutex_init(&para->fork[i], NULL);
		if (ret != 0)
			return (0);
	}
	return (1);
}

void	one_philo(t_para *para)
{
	para->start = timer();
	usleep(para->die_t * 1000);
	printf("%d : 1 died\n", para->die_t);
}
