/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_matrix1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:33:20 by yugao             #+#    #+#             */
/*   Updated: 2024/04/10 19:21:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	apoyo_matrix_init(t_node *node)
{
	node->obj = '#';
	node->stp = -1;
}

//创建一个对应大小的矩阵, 矩阵每个点都可以存储一个char和一个int
// Create a matrix of the corresponding size, each 
//point of the matrix can store a char and an int.
t_mtx	matrix_init(t_vec size)
{
	t_mtx	new;
	size_t	x;
	size_t	y;

	new = malloc (sizeof (t_node **) * ((int)(size.vx) + 1));
	if (!new)
		return (NULL);
	x = -1;
	while (++x < size.vx)
	{
		new[x] = malloc (sizeof (t_node *) * (((int)size.vy) + 1));
		if (!new[x])
			return (NULL);
		y = -1;
		while (++y < size.vy)
		{
			new[x][y] = malloc (sizeof (t_node));
			if (!new[x][y])
				return (NULL);
			apoyo_matrix_init (new[x][y]);
		}
		new[x][y] = NULL;
	}
	new[x] = NULL;
	return (new);
}

//显示矩阵, 用来查看矩阵的存储信息
//Display matrix, used to view the storage information of the matrix.
void	matrix_display(t_mtx matrix, t_bool	is_obj)
{
	int	x;
	int	y;

	if (!matrix)
		return ;
	y = 0;
	while (matrix[0][y])
	{
		x = 0;
		while (matrix[x] && matrix[x][y])
		{
			if (is_obj)
				printf ("(%d, %d) %c\t", x, y, matrix[x][y]->obj);
			else
				printf ("(%d, %d)%d\t", x, y, matrix[x][y]->stp);
			x ++;
		}
		printf ("\n");
		y ++;
	}
}

//对创建的矩阵进行销毁
// Destruction of created matrices
void	matrix_destory(t_mtx *matrix)
{
	t_mtx	trash;
	int		x;
	int		y;

	trash = *matrix;
	x = 0;
	while (trash[x])
	{
		y = 0;
		while (trash[x][y])
		{
			free (trash[x][y]);
			trash[x][y] = NULL;
			y ++;
		}
		free (trash[x]);
		trash[x] = NULL;
		x ++;
	}
	free (trash);
	trash = NULL;
}

//需要传入一个纯文本的字符串 不可以有换行符号, 与如果有的话 换行符也会被加入到矩阵中
// need to pass a plain text string without line breaks, 
//and if there are line breaks, they will be added to the matrix.
void	matrix_push(t_mtx *mtx_ori, char *context)
{
	int		i;
	int		leny;
	int		lenx;
	t_mtx	mtx;

	mtx = *mtx_ori;
	leny = 0;
	while (mtx[0][leny])
		leny ++;
	lenx = 0;
	while (mtx[lenx])
		lenx ++;
	i = 0;
	while (context[i])
	{
		if (i < lenx * leny)
			mtx[i % lenx][i / lenx]->obj = context[i];
		else
			return ;
		i ++;
	}
}

// int main(void)
// {
// 	t_mtx	test;

// 	test = matrix_init ((t_vec){2, 3});
// 	matrix_push (&test, "123456789");
// 	matrix_display (test, TRUE);
// 	matrix_destory (&test);
// 	return 0;
// }