/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/27 15:47:39 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_take_fork(t_philo *philo, t_state *state)
{
	if (!state->dead && state->is_create)
	{
		pthread_mutex_lock(philo->rfork);
		printf("%llu %d has taken a fork\n", (ph_get_time() - state->start), \
			philo->position);
		if (!state->dead && state->is_create)
		{
			pthread_mutex_lock(&philo->lfork);
			printf("%llu %d has taken a fork\n", (ph_get_time() - state->start), \
				philo->position);
		}
	}
}
