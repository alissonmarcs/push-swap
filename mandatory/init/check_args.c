#include <push_swap.h>

static	void	check_string_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			error();
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			error();
	}
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char *argv[])
{
	int		i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '\0')
			error();
		check_string_number(argv[i]);
	}
}
