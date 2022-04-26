/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:55:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/26 18:32:10 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

struct	s_state;

typedef struct s_philo
{
	struct s_state	*state;
	int				position; //a afficher + 1
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	int				count; //cmb de fois ils ont manger
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
	short			dead;
	short			is_create;
}					t_state;

#endif
