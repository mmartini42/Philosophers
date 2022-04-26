/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:55:42 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/26 18:43:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCTION_H
# define PHILO_FUNCTION_H

# include "philo.h"

/* Parsing */
bool	ph_parsing(int ac, char *av[]);

/* Utils */
void		ph_display_error(const char *str);
void		ph_display(const char *str);
int			ph_atoi(char *str);
uint64_t	ph_get_time(void);

/* Init */
bool		ph_init_philo(t_state *state);
bool		ph_init_state(t_state *state, int ac, char *av[]);

/* Philo */
void		ph_sleep(t_philo *philo, t_state *state);
void		ph_think(t_philo *philo, t_state *state);
void		ph_take_fork(t_philo *philo, t_state *state);
void		ph_eat(t_philo *philo, t_state *state);
void		ph_died(t_philo *philo);
void		ph_check_eat(t_state *state);

#endif
