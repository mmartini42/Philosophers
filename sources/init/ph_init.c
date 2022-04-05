/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:47:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/03 17:45:21 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_init_errors(int c)
{
	if (c == 0)
	{
		ph_display_error("Error init state");
		exit(EXIT_FAILURE);
	}
	else if (c == 1)
	{
		ph_display_error("Error Args");
		exit(EXIT_FAILURE);
	}
}

void	ph_destroy_state(t_state *state)
{
	size_t	i;

	if (state->fork_mut)
	{
		i = 0;
		while (i < state->amount)
			pthread_mutex_destroy(&state->fork_mut[i++]);
		free(state->fork_mut);
	}
	if (state->philos)
	{
		i = -1;
		while (++i < state->amount)
		{
			pthread_mutex_destroy(&state->philos[i].eat_mut);
			pthread_mutex_destroy(&state->philos[i].mutex);
		}
		free(state->philos);
	}
	pthread_mutex_destroy(&state->dead);
	pthread_mutex_destroy(&state->message);
}

void	ph_init_fork(t_state *state)
{
	size_t	i;

	pthread_mutex_init(&state->dead, NULL);
	pthread_mutex_init(&state->message, NULL);
	pthread_mutex_lock(&state->dead);
	state->fork_mut = (pthread_mutex_t *)malloc(sizeof(*(state->fork_mut)) \
		* state->amount);
	if (!state->fork_mut)
	{
		ph_display_error("Error init fork");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < state->amount)
		pthread_mutex_init(&state->fork_mut[i++], NULL);
}

void	ph_init_philo(t_state *state)
{
	size_t	i;

	state->philos = NULL;
	state->philos = (t_philo *)malloc(sizeof(*(state->philos)) * state->amount);
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
		state->philos[i].eat = 0;
		state->philos[i].count = 0;
		state->philos[i].state = state;
		pthread_mutex_init(&state->philos[i].eat_mut, NULL);
		pthread_mutex_init(&state->philos[i].mutex, NULL);
		pthread_mutex_lock(&state->philos[i].eat_mut);
		i++;
	}
}

t_state	*ph_init_state(int ac, char *av[])
{
	t_state	*state;

	state = malloc(sizeof(t_state *));
	if (!state)
		ph_init_errors(0);
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
	state->fork_mut = NULL;
	state->philos = NULL;
	dprintf(2, "%p\n", state);
	return (state);
}
