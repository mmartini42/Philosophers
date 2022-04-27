/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:26:09 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/27 17:18:28 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_died(t_philo *philo, t_state *state)
{
	if (!philo->state->dead && philo->state->is_create)
	{
		pthread_mutex_lock(&state->can_write);
		printf("%llu %d died\n", (ph_get_time() - philo->state->start), \
			philo->position);
		pthread_mutex_unlock(&state->can_write);
	}
	memset(&state->dead, 1, sizeof(short));
	memset(&state->is_create, 0, sizeof(short));
}
