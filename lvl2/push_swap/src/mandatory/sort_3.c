/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:18:36 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:22:42 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*min_node;
	t_stack	*max_node;

	min_node = find_smallest(*a);
	max_node = find_highest(*a);
	if (*a == max_node)
		ra(a, false);
	else if ((*a)->next == max_node)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}

void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_listsize(*a) > 3)
	{
		init_nodes(*a, *b);
		last_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
