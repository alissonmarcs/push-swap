#include "push_swap.h"

static	void	sort_argv_strings(char *argv[]);
static	t_node	*search_node(t_node *head, int number);

void	set_node_indexes(t_node *head, char *argv[])
{
	int		index;
	t_node	*node;

	index = 0;
	sort_argv_strings(argv);
	while (argv[++index])
	{
		node = search_node(head, ft_atoi(argv[index]));
		*(int *) &node->index = index;
	}
}

static	void	sort_argv_strings(char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
		}
	}
}

static	t_node	*search_node(t_node *head, int number)
{
	while (head)
	{
		if (head->number == number)
			return (head);
		head = head->next;
	}
	return (NULL);
}
