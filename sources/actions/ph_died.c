/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:26:09 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 18:14:32 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_press_f(t_state *state)
{
	size_t	i;

	if (state->philos)
	{
		i = -1;
		while (++i < state->amount)
		{
			pthread_mutex_destroy(&state->philos[i].lfork);
			pthread_mutex_destroy(state->philos[i].rfork);
		}
		free(state->philos);
		state->philos = NULL;
	}
	pthread_mutex_destroy(&state->dead);
	state = NULL;
	exit(EXIT_SUCCESS);
}

void	ph_died(t_philo *philo)
{
	printf("%llu %d died", (ph_get_time() - philo->state->start),\
		philo->position);
	ph_press_f(philo->state);
}
