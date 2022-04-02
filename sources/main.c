/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/03/21 17:38:45 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
// ./philo 10 10 5 5 [ 5 ]
//      0  1  2  3 4   5
static void	ph_first_part(int ac, char *av[], t_philo *philo)
{
	if (ac < 5)
		ph_exit_errors();
	ph_parsing(ac, av, philo);
}

int	main(int ac, char *av[])
{
	t_philo	philo;

	ph_first_part(ac, av, &philo);
}
