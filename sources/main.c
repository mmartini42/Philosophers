/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/03 17:45:51 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_first_part(int ac, char *av[], t_state **state)
{
	ph_parsing(ac, av);
	*state = ph_init_state(ac, av);
	dprintf(2, "%p\n", *state);
}

static void	ph_last_part(t_state **state)
{
	dprintf(2, "%p\n", *state);
	ph_destroy_state(*state);
	free(*state);
	*state = NULL;
}

int	main(int ac, char *av[])
{
	t_philo	philo;

	ph_first_part(ac, av, &philo.state);
	ph_last_part(&philo.state);
}
