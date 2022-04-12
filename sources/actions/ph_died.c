/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:26:09 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/12 18:25:56 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_died(t_philo *philo)
{
	if (!philo->state->dead)
		printf("%llu %d died\n", (ph_get_time() - philo->state->start),\
			philo->position);
	memset(&philo->state->dead, 1, sizeof(short));
}
