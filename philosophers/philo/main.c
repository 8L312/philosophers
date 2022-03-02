/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:18:35 by rmonney           #+#    #+#             */
/*   Updated: 2022/02/22 22:57:11 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_para	para;

	if ((argc != 5 && argc != 6) || !verifarg(argv))
	{
		printf("usage : ./philo [n of philo] [time to die] [time to eat]");
		printf(" [time to sleep] ([number of meals])\n");
		return (0);
	}
	else
	{
		if (!init(argv, &para))
			return (0);
	}
	if (para.nphilo == 1)
	{
		one_philo(&para);
		return (0);
	}
	if (!start(&para))
		return (0);
	return (0);
}
