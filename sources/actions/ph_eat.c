/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:38:10 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 18:13:05 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_eat(t_philo *philo, t_state *state)
{
	uint64_t	precision;

	if (!state->dead)
	{
		printf("%llu %d is eating", (ph_get_time() - state->start),\
			philo->position);
		philo->count += 1;
		philo->last_eat = ph_get_time();
		// usleep(state->to_eat * 1000);
		precision = ph_get_time();
		while (1)
		{
			if (ph_get_time() - precision >= state->to_eat)
				break ;
			usleep(10);
		}
	}
}
