/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:39:28 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/02 15:05:40 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_pars_errors(void)
{
	ph_display_error("Error Args");
	exit(EXIT_FAILURE);
}

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

void	ph_parsing(int ac, char *av[])
{
	size_t	i;

	if (ac < 5 || ac > 6)
		ph_pars_errors();
	i = 1;
	while (av[i])
	{
		if (!ph_is_number(av[i]))
			ph_pars_errors();
		i++;
	}
}
