/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:55:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/03 17:32:54 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

struct	s_state;

typedef struct s_philo
{
	struct s_state	*state;
	int				position;
	int				lfork;
	int				rfork;
	int				eat;
	int				count;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_mut;
}				t_philo;

typedef struct s_state
{
	size_t			amount;
	size_t			to_die;
	size_t			to_eat;
	size_t			to_sleep;
	int				must_eat;
	t_philo			*philos;
	pthread_mutex_t	*fork_mut;
	pthread_mutex_t	dead;
	pthread_mutex_t	message;
}					t_state;

#endif
