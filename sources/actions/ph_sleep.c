/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:18:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 17:24:13 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(t_philo *philo)
{
	ph_message(SLEEP, philo->state, philo->position);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	usleep(philo->state->to_sleep * 1000);
}
