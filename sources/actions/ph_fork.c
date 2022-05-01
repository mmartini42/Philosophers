/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/01 21:28:15 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_take_fork(t_philo *philo, t_state *state)
{
	pthread_mutex_lock(&philo->right_fork);
	if (!state->dead && state->is_create)
	{
		pthread_mutex_lock(philo->left_fork);
		ph_display(state, philo, FORK);
		if (!state->dead && state->is_create)
			ph_display(state, philo, FORK);
	}
}
