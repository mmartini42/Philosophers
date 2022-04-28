/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:23:16 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/28 15:16:15 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_display_error(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	ph_display(t_state *state, t_philo *philo, short action)
{
	uint64_t	difftime;

	pthread_mutex_lock(&state->can_write);
	if (!state->dead && state->is_create)
	{
		difftime = ph_get_time() - state->start;
		printf("%llu %d ", difftime, philo->position);
		if (action == FORK)
			printf("has taken a fork \n");
		else if (action == EAT)
			printf("is eating\n");
		else if (action == SLEEP)
			printf("is sleeping\n");
		else if (action == THINK)
			printf("is thinking\n");
		else if (action == DEAD)
			printf("died\n");
	}
	pthread_mutex_unlock(&state->can_write);
}
