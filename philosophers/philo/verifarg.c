/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:32:34 by rmonney           #+#    #+#             */
/*   Updated: 2022/02/03 18:08:40 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43)
		i++;
	while (str[i] != '\0')
	{
		if (47 < str[i] && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	verifarg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (isnum(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
