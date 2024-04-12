/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:22:00 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/10 19:22:25 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

t_node_hash	*list_init(void)
{
	t_node_hash	*new;

	new = malloc (sizeof (t_node_hash));
	if (!new)
		return (NULL);
	new->key = NULL;
	new->val = NULL;
	new->next = NULL;
	return (new);
}

t_bool	list_push(t_node_hash *l, char *key, char *val)
{
	t_node_hash	*new_node;
	t_node_hash	*current;

	current = l;
	new_node = list_init ();
	if (!new_node)
		return (FALSE);
	new_node->key = ft_strdup (key);
	new_node->val = ft_strdup (val);
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (TRUE);
}

t_bool	list_del(t_node_hash *l, char *key)
{
	t_node_hash	*current;
	t_node_hash	*prev;

	if (!l || !l->next)
	{
		ft_printf ("The list is empty!\n");
		return (FALSE);
	}
	prev = l;
	current = prev->next;
	while (current)
	{
		if (is_strsame (key, current->key))
		{
			prev->next = current->next;
			free (current->key);
			free (current->val);
			free (current);
			return (TRUE);
		}
		prev = current;
		current = current->next;
	}
	return (FALSE);
}

t_bool	list_grep(t_node_hash *l, char *key)
{
	t_node_hash	*tem;

	if (!l || !l->next)
	{
		ft_printf ("No element to find out!\n");
		return (FALSE);
	}
	else
	{
		tem = l->next;
		while (tem)
		{
			if (is_strsame (key, tem->key))
			{
				ft_printf ("GREP:\n\tKEY:%s VAL:%s\n", tem->key, tem->val);
				return (TRUE);
			}
			tem = tem->next;
		}
	}
	return (FALSE);
}

t_bool	list_destory(t_node_hash *l)
{
	t_node_hash	*cur;
	t_node_hash	*trash;

	if (!l || !l->next)
		return (TRUE);
	cur = l->next;
	trash = NULL;
	while (cur)
	{
		trash = cur;
		cur = cur->next;
		if (trash->val)
			free (trash->val);
		if (trash->key)
			free (trash->key);
		free (trash);
	}
	free (l);
	l = NULL;
	return (TRUE);
}
