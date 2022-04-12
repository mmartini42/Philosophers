/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:18:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 18:26:00 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(t_philo *philo, t_state *state)
{
	uint64_t	start;

	if (!state->dead)
	{
		printf("%llu %d is sleeping\n", (ph_get_time() - state->start),\
			philo->position);
		pthread_mutex_unlock(&philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		start = ph_get_time();
		while (1)
		{
			if ((ph_get_time() - start) >= state->to_sleep)
				break ;
			usleep (10);
		}
	}
}
