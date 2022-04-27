/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:12:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/27 17:04:49 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_think(t_philo *philo, t_state *state)
{
	if (!state->dead && state->is_create)
	{
		pthread_mutex_lock(&state->can_write);
		printf("%llu %d is thinking\n", (ph_get_time() - state->start), \
			philo->position);
		pthread_mutex_unlock(&state->can_write);
	}
}
