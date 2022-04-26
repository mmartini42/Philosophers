/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:21:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/26 18:43:32 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ph_check_max_eat(t_state *state)
{
	size_t	i;

	if (state->must_eat == -1)
		return (true);
	i = 0;
	while (i < state->amount)
	{
		if (state->must_eat > state->philos[i].count)
			return (true);
		i++;
	}
	return (false);
}

void	ph_check_eat(t_state *state)
{
	size_t		index;
	uint64_t	diff;

	while (state->is_create)
	{
		if (!ph_check_max_eat(state))
			return ;
		index = 0;
		while (index < state->amount)
		{
			pthread_mutex_lock(&state->check_meal);
			diff = ph_get_time() - state->philos[index].last_eat;
			if (diff >= state->to_die)
			{
				ph_died(state->philos);
				return ;
			}
			index++;
		}
	}
}
