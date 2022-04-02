/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:55:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/03/29 18:31:59 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

struct s_state;

typedef struct s_philo
{
	struct s_state	*state;
}				t_philo;

typedef struct	s_state
{
	int		amount;
	size_t	to_die;
	size_t	to_eat;
	size_t	to_sleep;
	int		must_eat;
	t_philo	*philos;
}				t_state;

#endif
