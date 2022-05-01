/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:26:09 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/01 21:26:13 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_died(t_philo *philo, t_state *state)
{
	if (!state->dead && state->is_create && philo->is_alive)
		ph_display(state, philo, DEAD);
	memset(&state->dead, 1, sizeof(short));
	memset(&state->is_create, 0, sizeof(short));
	philo->is_alive = 0;
}
