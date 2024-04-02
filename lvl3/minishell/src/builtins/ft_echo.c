/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/04/01 22:07:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(t_mini *mini, char **arguments, int flag)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arguments[len])
		len++;
	(void) mini;
	while (i < len)
	{
		printf("%s", arguments[i]);
		if (i + 1 != len)
			printf("%c", ' ');
		i++;
	}
	if (flag == FALSE)
		printf("\n");
	return (EXIT_SUCCESS);
}

/*int	main(int argc, char **argv, char **envp)
{
	t_mini 	mini;
	argc = 0;
	argv = NULL;
	char *arr[7];
	arr[0] = "hola";
	arr[1] = "paco";
	arr[2] = "hola";
	arr[3] = "paco";
	arr[4] = "hola";
	arr[5] = "paco";
	arr[6] = NULL;

	init_env(&mini, envp);
	ft_echo(&mini, (char **)arr, FALSE);
	//system("leaks -q minishell");
	return (0);
}*/