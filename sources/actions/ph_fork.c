/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/28 15:00:11 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_take_fork(t_philo *philo, t_state *state)
{
	if (!state->dead && state->is_create)
	{
		pthread_mutex_lock(philo->rfork);
		ph_display(state, philo, FORK);
		if (!state->dead && state->is_create)
		{
			pthread_mutex_lock(&philo->lfork);
			ph_display(state, philo, FORK);
		}
	}
}
