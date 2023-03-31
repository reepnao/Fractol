/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:56:11 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/26 14:13:08 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_mlx(t_fractol *frctl)
{
	t_mlx	*mlx;

	frctl->mlx = malloc(sizeof(t_mlx));
	if (frctl->mlx == NULL)
		free_kill_all(frctl);
	mlx = frctl->mlx;
	mlx->ptr = mlx_init();//initialization = baslatmak
	if (mlx->ptr == NULL)
		free_kill_all(frctl);
	mlx->win = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "fractol");
	if (mlx->win == NULL)
		free_kill_all(frctl);
	mlx->img.ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);//-> ile . farki ne? mlx pointer old icin "->" ile gosterdik, fakat img pointer olmadigi icin "." koyuyoruz
	if (mlx->img.ptr == NULL)
		free_kill_all(frctl);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);// uygulama acikken bu oranlari degistirebiliyorsun.
	if (mlx->img.addr == NULL)
		free_kill_all(frctl);
	mlx_key_hook(mlx->win, key_actions, frctl);
	mlx_mouse_hook(mlx->win, zoom, frctl);
	mlx_hook(mlx->win, 17, 0, free_kill_all, frctl);    // 17 = durdurma anlamina geliyor. 0 -> tusa basildigi anda komutu calistiracak

	mlx_hook(mlx->win, 6, 0, julia_mouse_motion, frctl);// 6 = mouse move anlamina geliyor.
}
