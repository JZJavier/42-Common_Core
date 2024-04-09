/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:56:09 by yugao             #+#    #+#             */
/*   Updated: 2024/04/06 01:17:57 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//这个是初始化t_info参数中的img_info类型的函数 
//This is the function that initializes the 
//img_info type in the t_info parameter
void	img_new(void *info)
{
	t_info	*tem;

	tem = (t_info *)info;
	tem->img_info.img = mlx_new_image (tem->mlx,
			tem->map_info.x, tem->map_info.y);
	tem->img_info.addr = mlx_get_data_addr (tem->img_info.img,
			&(tem->img_info.bits_per_pixel),
			&(tem->img_info.len_line), &(tem->img_info.endian));
}

//在上面的函数用完以后, 这个函数负责在我们创建的图像中画图像
//After the above function has been used, this 
//function is responsible for drawing the image in the image we created.
void	img_put_pixel(void *info, int x, int y, int color)
{
	char	*dst;
	t_info	*tem;

	tem = (t_info *)info;
	if (x < 0 || x >= tem->map_info.x || y < 0 || y >= tem->map_info.y)
		return ;
	dst = tem->img_info.addr + (y * tem->img_info.len_line + x
			* (tem->img_info.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//画任何东西的时候, 必须以这个函数为开始, 否则会出错
//运行这个函数时, 如果旧画布有内容, 旧画布的内容会被立即推送到屏幕上
//然后会开始新的画布
//When drawing anything, you must start with 
//this function, otherwise you will get an error.
//When running this function, if the old canvas has content, 
//the content of the old canvas will be pushed to the screen immediately.
//Then a new canvas will be started
void	img_start_draw(void *info)
{
	t_info	*tem;

	tem = (t_info *)info;
	if (tem->img_info.img)
		mlx_put_image_to_window (tem->mlx, tem->win, tem->img_info.img, 0, 0);
	img_new (info);
}

//在结束一张画布的时候, 必须以这个函数为结束, 这样才能将画的内容推送到窗口并销毁图像
// When ending a canvas, you must end it with this function so that 
//you can push the contents of the canvas to the window and destroy the image.
void	img_end_draw(void *info)
{
	t_info	*tem;

	tem = (t_info *)info;
	mlx_put_image_to_window (tem->mlx, tem->win, tem->img_info.img, 0, 0);
	mlx_destroy_image (tem->mlx, tem->img_info.img);
	tem->img_info.img = NULL;
}

//在画任何东西之前, 如果想要改变颜色, 可以通过这个函数改变颜色
//默认颜色为白色
// Before drawing anything, if you want to change the
// color, you can change the color with this function.
// Default color is white
void	img_set_color(void *info, int new_color)
{
	t_info	*tem;

	tem = (t_info *)info;
	tem->color = new_color;
}
