/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:15:49 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 18:53:58 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	argv = parse(argc, argv);
	init_node(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (ft_listsize(a) == 2)
			sa(&a, false);
		else if (ft_listsize(a) == 3)
			sort_3(&a);
		else
			push_swap(&a, &b);
	}
	ft_lstclear(&a);
	return (0);
}
