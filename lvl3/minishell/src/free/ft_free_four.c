/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:48:04 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 01:42:35 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_four(char **one, char **two, char **three, char **four)
{
	free(*one);
	free(*two);
	free(*three);
	free(*four);
	*one = NULL;
	*two = NULL;
	*three = NULL;
	*four = NULL;
}
