/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:42:44 by utente            #+#    #+#             */
/*   Updated: 2024/03/26 17:59:39 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../Libft/libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int					number;
	int					index;
	int					push_price;
	bool				is_above_median;
	bool				cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;	

/*	-------------------------- PARSE ---------------------------*/
int		is_num(char *str);
char	**parse(int argc, char **argv);

/*	-------------------------- ERROR ---------------------------*/
void	print_error(void);

/*	-------------------------- LIST ---------------------------*/
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **stack);
int		ft_listsize(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack	*ft_lstnew(int number);

/*	-------------------------- STACK ---------------------------*/
int		is_sorted(t_stack *stack);
void	add_back(t_stack **stack, int number);

/*	-------------------------- INIT ---------------------------*/
void	init_node(t_stack **a, char **argv);
void	init_target(t_stack *a, t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
void	init_index(t_stack *stack);
void	init_price(t_stack *a, t_stack *b);
void	init_cheapest(t_stack *b);

/*	-------------------------- FIND ---------------------------*/
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*find_highest(t_stack *stack);

/*	-------------------------- ALGOS ---------------------------*/
void	last_rotation(t_stack **stack, t_stack *head, char stack_name);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);

/*	------------------------- ROTATIONS --------------------------*/
/*	---------------------------- PUSH ----------------------------*/
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);

/*	----------------------- REVERSE ROTATE ------------------------*/
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

/*	--------------------------- ROTATE -----------------------------*/
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);

/*	---------------------------- SWAP ------------------------------*/
void	swap(t_stack **head);
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

#endif
