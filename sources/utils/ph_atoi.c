/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:30:02 by mathmart          #+#    #+#             */
/*   Updated: 2022/04/03 12:30:11 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_atoi(char *str)
{
	unsigned int	result;
	size_t			i;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && (str[i] >= 9 && str[i] <= 13) && str[i] == ' ')
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
