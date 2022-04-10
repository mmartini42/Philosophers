/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:57:02 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 17:43:01 by mathmart         ###   ########.fr       */
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

void	ph_display(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ph_message(int action, t_state *state, int position)
{
	position += 1;
	//Verifier si 0 mort pour ecrire
	if (action == FORK)
		printf("%llu %d has taken a fork", (ph_get_time() - state->start),\
			position);
	else if (action == EAT)
		printf("%llu %d is eating", (ph_get_time() - state->start),\
			position);
	else if (action == SLEEP)
		printf("%llu %d is sleeping", (ph_get_time() - state->start),\
			position);
	else if (action == THINK)
		printf("%llu %d is thinking", (ph_get_time() - state->start),\
			position);
}
