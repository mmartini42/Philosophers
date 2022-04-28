/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:55:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/28 14:31:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

struct	s_state;

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}			t_action;

typedef struct s_philo
{
	struct s_state	*state;
	int				position;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	int				count;
	uint64_t		last_eat;
}				t_philo;

typedef struct s_state
{
	size_t			amount;
	size_t			to_die;
	size_t			to_eat;
	size_t			to_sleep;
	int				must_eat;
	t_philo			*philos;
	pthread_t		*tid;
	uint64_t		start;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	can_write;
	short			dead;
	short			is_create;
}					t_state;

#endif
