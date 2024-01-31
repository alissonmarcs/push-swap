#include <push_swap.h>

static	void	error(void);
static	void	check_string_number(char *str);

void	check_args(char *argv[])
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '\0')
			error();
		check_string_number(argv[i]);
	}
}

static	void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static	void	check_string_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i])
			error();
	}
}
