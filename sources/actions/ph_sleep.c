/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:18:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/28 14:41:39 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(t_philo *philo, t_state *state)
{
	uint64_t	difftime;

	if (!state->dead && state->is_create)
	{
		difftime = ph_get_time();
		while (1)
		{
			if ((ph_get_time() - difftime) >= state->to_sleep)
				break ;
			usleep (10);
		}
		pthread_mutex_unlock(&philo->lfork);
		pthread_mutex_unlock(philo->rfork);
	}
}
