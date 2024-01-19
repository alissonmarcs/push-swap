#include "push_swap.h"

static	void	error(void);
static	void	check_duplicates(long current_number, char *argv[]);
static	void	check_string_number(char *str);

void	check_args(int argc, char *argv[])
{
	int		i;
	long	current_number;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 0;
	while (argv[++i])
	{
		check_string_number(argv[i]);
		current_number = ft_atol(argv[i]);
		if (current_number < INT_MIN || current_number > INT_MAX)
			error();
		check_duplicates(current_number, argv);
	}
}

static	void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static	void	check_duplicates(long current_number, char *argv[])
{
	int		i;
	int		ocorrences;
	long	next_number;

	i = 0;
	ocorrences = 0;
	while (argv[++i])
	{
		next_number = ft_atol(argv[i]);
		if (current_number == next_number)
			ocorrences++;
	}
	if (ocorrences != 1)
		error();
}

static	void	check_string_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		error();
}
