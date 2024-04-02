/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:14:06 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 08:08:54 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	event(void)
{
	return (EXIT_SUCCESS);
}

static void	sig_hand(int sig)
{
	(void)sig;
	printf ("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_sig(void)
{
	struct sigaction	act;

	act.sa_handler = sig_hand;
	sigemptyset (&act.sa_mask);
	act.sa_flags = 0;
	rl_event_hook = event;
	sigaction (SIGINT, &act, NULL);
	signal (SIGQUIT, SIG_IGN);
}

void	init_sig_child(void)
{
	signal (SIGINT, SIG_DFL);
	signal (SIGQUIT, SIG_IGN);
}
