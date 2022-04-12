/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:12:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 17:13:56 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_think(t_philo *philo, t_state *state)
{
	if (!state->dead)
		printf("%llu %d died", (ph_get_time() - state->start),\
			philo->position);
}
