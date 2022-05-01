/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:38:10 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/01 21:32:03 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_eat(t_philo *philo, t_state *state)
{
	uint64_t	difftime;

	if (!state->dead && state->is_create && philo->is_alive)
	{
		ph_display(state, philo, EAT);
		philo->count += 1;
		philo->last_eat = ph_get_time();
		difftime = ph_get_time();
		while (1)
		{
			if ((ph_get_time() - difftime) >= state->to_eat)
				break ;
			usleep(10);
		}
	}
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
