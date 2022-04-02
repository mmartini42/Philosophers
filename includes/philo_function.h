/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:55:42 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/02 16:02:51 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCTION_H
# define PHILO_FUNCTION_H

# include "philo.h"

/* Parsing */
void	ph_parsing(int ac, char *av[]);

/* Utils */
/* Displays */
void	ph_display_error(const char *str);
void	ph_display(const char *str);

/* Init */
void	ph_init_philo(t_state *state);
t_state	*ph_init_state(int ac, char *av[]);

# endif
