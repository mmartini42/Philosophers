/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:55:42 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/10 17:24:51 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCTION_H
# define PHILO_FUNCTION_H

# include "philo.h"

/* Parsing */
void		ph_parsing(int ac, char *av[]);

/* Utils */
void		ph_display_error(const char *str);
void		ph_display(const char *str);
void		ph_message(int action, t_state *state, int position);
int			ph_atoi(char *str);
uint64_t	ph_get_time(void);

/* Init */
void		ph_init_philo(t_state *state);
void		ph_init_state(t_state *state, int ac, char *av[]);
// void		ph_destroy_state(t_state *state);

/* Philo */
void		*ph_main_func(void *data);
void		ph_sleep(t_philo *philo);

#endif
