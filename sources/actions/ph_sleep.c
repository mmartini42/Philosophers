/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:18:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/01 21:32:23 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(t_philo *philo, t_state *state)
{
	uint64_t	difftime;

	if (!state->dead && state->is_create && philo->is_alive)
	{
		ph_display(state, philo, SLEEP);
		difftime = ph_get_time();
		while (1)
		{
			if ((ph_get_time() - difftime) >= state->to_sleep)
				break ;
			usleep (10);
		}
	}
}
