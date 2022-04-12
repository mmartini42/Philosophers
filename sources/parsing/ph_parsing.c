/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:39:28 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 15:17:13 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ph_is_number(char *nb)
{
	size_t	i;

	i = 0;
	while (nb[i])
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	ph_parsing(int ac, char *av[])
{
	size_t	i;

	if (ac < 5 || ac > 6)
		return (false);
	i = 1;
	while (av[i])
	{
		if (!ph_is_number(av[i]))
			return (false);
		i++;
	}
	return (true);
}
