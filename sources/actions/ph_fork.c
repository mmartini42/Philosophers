/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 17:35:18 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_take_fork(t_philo *philo, t_state *state)
{
	if (!state->dead)
	{
		pthread_mutex_lock(philo->rfork);
		printf("%llu %d is eating", (ph_get_time() - state->start),\
			philo->position);
		if (!state->dead)
		{
			pthread_mutex_lock(&philo->lfork);
			printf("%llu %d is eating", (ph_get_time() - state->start),\
				philo->position);
		}
	}
}
