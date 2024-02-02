/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:45:19 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/02 16:45:20 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_atol(char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		sign = 1 - 2 * (*str++ == '-');
	while (ft_isdigit(*str))
	{
		result = 10 * result + (*str - '0');
		str++;
	}
	return (result * sign);
}
