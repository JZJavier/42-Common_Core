/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:33:33 by javgao            #+#    #+#             */
/*   Updated: 2024/04/01 21:13:36 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	if (argc > 1)
		return (print_error ("More than one argument"));
	init_mini (&mini, envp);
	init_sig ();
	rl_on_new_line ();
	shell_loop (&mini);
	hash_destory (mini.hash_env);
	(void)argv;
	return (0);
}
