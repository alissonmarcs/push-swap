#include "libft.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
		sign = 1 - 2 * (*str++ == '-');
	while (ft_isdigit(*str))
	{
		result = 10 * result + (*str - '0');
		str++;
	}
	return (result * sign);
}
