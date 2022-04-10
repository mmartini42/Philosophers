/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:47:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 16:02:46 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_init_errors(int c)
{
	if (c == 0)
	{
		ph_display_error("Error init philo");
		exit(EXIT_FAILURE);
	}
	else if (c == 1)
	{
		ph_display_error("Error Args");
		exit(EXIT_FAILURE);
	}
}

void	ph_init_philo(t_state *state)
{
	size_t	i;

	state->philos = (t_philo *)malloc(sizeof(*(state->philos)) * state->amount);
	if (!state->philos)
		ph_init_errors(0);
	i = 0;
	state->start = ph_get_time();
	while (i < state->amount)
	{
		state->philos[i].position = i;
		pthread_mutex_init(&state->philos[i].lfork, NULL);
		state->philos[i].rfork = &state->philos[(i + 1) % state->amount].lfork;
		state->philos[i].count = 0;
		state->philos[i].last_eat = 0;
		state->philos[i].state = state;
		pthread_create(&state->philos[i].tid, NULL, ph_main_func, state->philos);
		i++;
	}
}

void	ph_init_state(t_state *state, int ac, char *av[])
{
	state->amount = ph_atoi(av[1]);
	state->to_die = ph_atoi(av[2]);
	state->to_eat = ph_atoi(av[3]);
	state->to_sleep = ph_atoi(av[4]);
	if (ac == 6)
		state->must_eat = ph_atoi(av[5]);
	else
		state->must_eat = 0;
	if (state->amount < 2 || state->amount > 200
		|| state->to_die < 60 || state->to_eat < 60
		|| state->to_sleep < 60 || state->must_eat < 0)
		ph_init_errors(1);
	state->philos = NULL;
	pthread_mutex_init(&state->dead, NULL);
}
