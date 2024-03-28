/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:47:46 by utente            #+#    #+#             */
/*   Updated: 2024/03/29 00:30:24 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	error(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	command(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		pa(a, b, true);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(b, a, true);
	else if (ft_strcmp(command, "sa\n") == 0)
		sa(a, true);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b, true);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b, true);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a, true);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b, true);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b, true);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a, true);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b, true);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(a, b, true);
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (1 == argc)
		return (0);
	argv = parse(argc, argv);
	init_node(&a, argv + 1);
	len = ft_listsize(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && ft_listsize(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}
