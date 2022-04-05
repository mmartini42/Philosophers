/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:55:42 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/03 17:45:29 by mathmart         ###   ########.fr       */
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
int			ph_atoi(char *str);
uint64_t	get_time(void);

/* Init */
void		ph_init_philo(t_state *state);
t_state		*ph_init_state(int ac, char *av[]);
void		ph_destroy_state(t_state *state);
#endif
