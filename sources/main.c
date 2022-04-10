/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 16:02:40 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_first_part(int ac, char *av[], t_state *state)
{
	ph_parsing(ac, av);
	ph_init_state(state, ac, av);
	ph_init_philo(state);
}

void	*ph_main_func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	return (NULL);
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
	pthread_mutex_destroy(&state->dead);
	state = NULL;
}

int	main(int ac, char *av[])
{
	t_state	state;

	ph_first_part(ac, av, &state);
	ph_last_part(&state);
	return (0);
}
