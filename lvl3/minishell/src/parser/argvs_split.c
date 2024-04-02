/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvs_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:46:39 by yugao             #+#    #+#             */
/*   Updated: 2024/03/14 07:03:13 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//555555555
//这是一个创建字符串的文件, 初始化以后, 可以不断添加单个字符, 长度自动扩张.
//es una funcion conque hacemos una cadena con un tamaño flexible
//pasamos la direccion de un puntero char, y el char que queramos añadir
//si añadimos con exito tenemos true, si no , tenemos false
int	chr_add(char **chrs, char c)
{
	char	*tem;

	if (!*chrs)
	{
		*chrs = malloc (sizeof (char) * 2);
		if (!*chrs)
			return (FALSE);
		(*chrs)[0] = c;
		(*chrs)[1] = '\0';
		return (TRUE);
	}
	tem = malloc (sizeof (char) * (ft_strlen (*chrs) + 2));
	if (!tem)
		return (FALSE);
	ft_strcpy (tem, *chrs);
	tem[ft_strlen (*chrs)] = c;
	tem[ft_strlen (*chrs) + 1] = '\0';
	free (*chrs);
	*chrs = tem;
	return (TRUE);
}

//处理大于号 小于号和 管道符号情况
//abordar la situacion de BIG LITTLE PIPE char
//tambien se usa para ajustar la posicion del puntero que
//usamos en el bucle en la funcion split_args
static void	is_chr_special(char **c, char ***new_args, char **new_arg)
{
	if (**c == PIPE || **c == BIG || **c == LIT)
	{
		arry_refresh (new_args, new_arg);
		if (**c == BIG && *(*c + 1) && *(*c + 1) == BIG)
		{
			arry_add (new_args, ">>");
			(*c) += 1;
			return ;
		}
		if (**c == LIT && *(*c + 1) && *(*c + 1) == LIT)
		{
			arry_add (new_args, "<<");
			(*c) += 1;
			return ;
		}
		if (**c == PIPE)
			arry_add (new_args, PIPES);
		if (**c == BIG)
			arry_add (new_args, BIGS);
		if (**c == LIT)
			arry_add (new_args, LITS);
	}
}

//abordar las comillas , y ajustar la posicion del puntero que usamos en
//la funcion split_args
static void	is_chr_quote(char **c, char ***new_args, char **new_arg)
{
	char	mark;

	if (**c == QUOTE_LIT)
		mark = QUOTE_LIT;
	else if (**c == QUOTE_BIG)
		mark = QUOTE_BIG;
	else
		return ;
	if (*(*c - 1) == ' ')
		arry_refresh (new_args, new_arg);
	chr_add (new_arg, **c);
	(*c) += 1;
	while (**c != mark && **c)
	{
		chr_add (new_arg, **c);
		(*c) += 1;
	}
	chr_add (new_arg, **c);
	if (*(*c + 1) && *(*c + 1) == ' ')
		arry_refresh (new_args, new_arg);
}

//控制tem指针的位置将\b格跳过去
//controtar el puntero *tem para saltar a los espacios
static void	skip_space(char **tem)
{
	while (**tem && **tem != ' ')
		(*tem) += 1;
}

//将一个字符串进行分割， 碰到< > | " ' 和几个符号进行分割， 目前的问题是当有两个引号同时围住一个元素的时候
//会按照最近的阔考进行配对
//在这个函数中 ori这个参数是函数使用者负责 如果是申请的变量要用户去释放， 函数内不对ori这个参数进行释放
// Dividir una cadena en partes, al encontrarse con los 
//símbolos < > | " ' se realizará la división. 
//El problema actual es que cuando dos comillas rodean un elemento, 
//se emparejarán según la comilla más cercana.
// En esta función, el parámetro ori es responsabilidad 
//del usuario. Si es una variable asignada, el usuario debe liberarla.
//La función no liberará el parámetro ori.
void	split_args(char ***args, char *ori)
{
	char	*tem;
	char	*new_arg;
	char	**new_args;

	new_arg = NULL;
	new_args = NULL;
	tem = ft_strtrim (ori, " ");
	ori = tem;
	while (*tem)
	{
		if (*tem == ' ' && new_arg)
		{
			arry_refresh (&new_args, &new_arg);
			skip_space (&tem);
		}
		is_chr_special (&tem, &new_args, &new_arg);
		is_chr_quote (&tem, &new_args, &new_arg);
		if (is_not_key (*tem))
			chr_add (&new_arg, *tem);
		tem ++;
	}
	arry_refresh (&new_args, &new_arg);
	free (ori);
	*args = new_args;
}
