/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 17:37:55 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_take_fork(t_philo *philo)
{
	ph_message(FORK, philo->state, philo->position);
	pthread_mutex_lock(&philo->lfork);
	pthread_mutex_lock(&philo->rfork);
}
