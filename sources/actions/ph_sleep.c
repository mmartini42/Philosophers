/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:18:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 17:28:55 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(t_philo *philo, t_state *state)
{
	if (!state->dead)
		printf("%llu %d is sleeping", (ph_get_time() - state->start),\
			philo->position);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	usleep(state->to_sleep * 1000);
}
