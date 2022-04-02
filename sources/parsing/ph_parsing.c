/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:39:28 by mathmart          #+#    #+#             */
/*   Updated: 2022/03/29 18:37:39 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_pars_errors(void)
{
	ph_display_error("Error Args");
	exit(EXIT_FAILURE);
}

static int	ph_atoi(char *str)
{
	unsigned int	result;
	size_t			i;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && is_whitespace(str[i]))
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

static bool	ph_is_number(char *nb)
{
	size_t	i;

	i = 0;
	while (nb[i])
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

static void	ph_init_philo(t_state *state)
{
	state->philos = NULL;
	state->philos = (t_philo*)malloc(sizeof(*(state->philos)) * state->amount);
	if (state->philos)
	{
		ph_display_error("Error malloc");
		exit(EXIT_FAILURE);
	}
}

void	ph_parsing(int ac, char *av[], t_philo *philo)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (!ph_is_number(av[i]))
			ph_pars_errors();
		i++;
	}
	philo->state->amount = ph_atoi(av[1]);
	philo->state->to_die = ph_atoi(av[2]);
	philo->state->to_eat = ph_atoi(av[3]);
	philo->state->to_sleep = ph_atoi(av[4]);
	if (ac == 6)
		philo->state->must_eat = ph_atoi(av[5]);
	else
		philo->state->must_eat = 0;
	if (philo->state->amount < 2 || philo->state->amount > 200 || 
		philo->state->to_die < 60 || philo->state->to_eat < 60 || 
		philo->state->to_sleep < 60 || philo->state->must_eat < 0)
		ph_pars_errors();
	ph_init_philo(philo->state);
}
