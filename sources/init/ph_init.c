/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:47:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/02 17:23:37 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_atoi(char *str)
{
	unsigned int	result;
	size_t			i;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && (str[i] >= 9 && str[i] <= 13) && str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((sign == 1 && result > (unsigned int)(INT_MAX))
		|| (sign == -1 && result > (unsigned int)(INT_MAX) + 1))
		errno = ERANGE;
	return ((int)result * sign);
}

void	ph_init_philo(t_state *state)
{
	size_t	i;

	state->philos = NULL;
	state->philos = (t_philo*)malloc(sizeof(*(state->philos)) * state->amount);
	if (state->philos)
	{
		ph_display_error("Error init philo");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < state->amount)
	{
		state->philos[i].position = i;
		state->philos[i].lfork = i;
		state->philos[i].rfork = i + (1 % state->amount);
		i++;
	}
}

t_state	*ph_init_state(int ac, char *av[])
{
	t_state *state;
	
	state = malloc(sizeof(t_state *));
	if (!state)
	{
		ph_display_error("Error init state");
		exit(EXIT_FAILURE);
	}
	state->amount = ph_atoi(av[1]);
	state->to_die = ph_atoi(av[2]);
	state->to_eat = ph_atoi(av[3]);
	state->to_sleep = ph_atoi(av[4]);
	if (ac == 6)
		state->must_eat = ph_atoi(av[5]);
	else
		state->must_eat = 0;
	if (state->amount < 2 || state->amount > 200 || 
		state->to_die < 60 || state->to_eat < 60 || 
		state->to_sleep < 60 || state->must_eat < 0)
	{
		ph_display_error("Error Args");
		exit(EXIT_FAILURE);
	}
	return (state);
}