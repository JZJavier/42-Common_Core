/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:37:28 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/22 10:00:44 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

//List
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

// Create stack
void	ft_create_stack(t_list **stack, int argc, char **argv);

// Check arguments
void	ft_check_args(int argc, char **argv);

//Get_distance
int		get_distance(t_list **stack, int index);

// Free
void	free_stack(t_list **stack);
void	ft_free(char **str);

//Small numbers
int		get_min(t_list **stack, int val);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);

//Sort 3
void	sort_3_part2(t_list **stack_a);
void	sort_3(t_list **stack_a);

//Index
void	index_stack(t_list **stack);
t_list	*get_next_min(t_list **stack);

//Radix
void	radix_sort(t_list **stack_a, t_list **stack_b);

//Sorted
int		ft_check_sorted(t_list **stack);

//Error
void	ft_error(void);

// Operations
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverserotate(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif
