/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 01:38:15 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_mini *mini)
{
	hash_display(*mini->hash_env);
	return (EXIT_SUCCESS);
}
/*int	main(int argc, char **argv, char **envp) 			//TIENE LEAKSSSSSSSS
{
	t_mini 	mini;
	argc = 0;
	argv = NULL;
	init_env(&mini, envp);
	ft_env(&mini);
	system("leaks -q minishell");
	return (0);
}*/