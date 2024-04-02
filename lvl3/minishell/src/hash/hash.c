/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:30:00 by yugao             #+#    #+#             */
/*   Updated: 2024/03/13 08:02:18 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_hash	*hash_init(void)
{
	t_hash	*new_hash;
	int		i;

	i = 0;
	new_hash = malloc (sizeof (t_hash));
	if (!new_hash)
		return (NULL);
	while (i < HASH_SIZE)
	{
		new_hash->bucket[i] = NULL;
		i ++;
	}
	return (new_hash);
}

t_bool	hash_push(t_hash *h, char *key, char *val)
{
	int	index;

	index = hash_func (key);
	if (hash_grep (h, key))
		hash_del (h, key);
	if (!h->bucket[index])
	{
		h->bucket[index] = list_init ();
		if (!h->bucket[index])
			return (FALSE);
		list_push (h->bucket[index], key, val);
		return (TRUE);
	}
	else
	{
		list_push (h->bucket[index], key, val);
		return (TRUE);
	}
}

char	*hash_grep(t_hash *h, char *key)
{
	int		index;
	t_node	*tem;

	index = hash_func (key);
	if (!h->bucket[index])
		return (NULL);
	tem = h->bucket[index];
	while (tem)
	{
		if (is_strsame (tem->key, key))
			return (tem->val);
		tem = tem->next;
	}
	return (NULL);
}

t_bool	hash_destory(t_hash	*h)
{
	int	i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (h->bucket[i])
			list_destory (h->bucket[i]);
		i ++;
	}
	free (h);
	h = NULL;
	return (TRUE);
}

t_bool	hash_del(t_hash	*h, char *key)
{
	int		index;

	index = hash_func (key);
	if (!h->bucket[index])
		printf ("%s no exist!\n", key);
	list_del (h->bucket[index], key);
	return (TRUE);
}
