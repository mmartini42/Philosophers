/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:38:10 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 17:48:41 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_philo_satiate(t_state *state)
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

void	ph_eat(t_philo *philo)
{
	philo->last_eat = ph_get_time();
	if (philo->count == philo->state->must_eat && philo->state->must_eat > 0)
		ph_philo_satiate(philo->state);
	philo->count += 1;
	ph_message(EAT, philo->state, philo->position);
	pthread_mutex_lock(&philo->lfork);
	pthread_mutex_lock(philo->rfork);
	usleep(philo->state->to_eat * 1000);
}
