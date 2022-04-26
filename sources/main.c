/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/26 18:50:40 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
*/

static bool	ph_first_part(int ac, char *av[], t_state *state)
{
	if (!ph_parsing(ac, av))
	{
		ph_display_error("Error Args");
		return (false);
	}
	if (!ph_init_state(state, ac, av) || !ph_init_philo(state))
		return (false);
	return (true);
}

static void	*ph_main_func(void *data)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)data;
	state = philo->state;
	if (philo->position % 2 == 0)
		usleep(state->to_eat);
	while (!state->dead)
	{
		ph_take_fork(philo, state);
		ph_eat(philo, state);
		ph_sleep(philo, state);
		ph_think(philo, state);
	}
	return (NULL);
}

static void	ph_simulation(t_state *state)
{
	size_t	i;

	memset(&state->is_create, 1, sizeof(short));
	state->start = ph_get_time();
	i = 0;
	while (i < state->amount)
	{
		if (pthread_create(&state->tid[i], NULL,
			ph_main_func(state->philos), &state->philos[i]) != 0)
			memset(&state->is_create, 0, sizeof(short));
		i++;
	}
	ph_check_eat(state);
	i = 0;
	while (i < state->amount)
	{
		pthread_detach(state->tid[i]);
		i++;
	}
}

static void	ph_last_part(t_state *state)
{
	size_t	i;

	if (state->philos)
	{
		i = -1;
		while (++i < state->amount)
		{
			pthread_mutex_destroy(&state->philos[i].lfork);
			pthread_mutex_destroy(state->philos[i].rfork);
		}
		free(state->philos);
		state->philos = NULL;
	}
	state = NULL;
}

int	main(int ac, char *av[])
{
	t_state	state;

	if (!ph_first_part(ac, av, &state))
		return (EXIT_FAILURE);
	ph_simulation(&state);
	ph_last_part(&state);
	return (0);
}
