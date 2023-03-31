/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:11:52 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/27 13:48:11 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(int argc, char *argv[])
{
	t_fractol	*frctl;

	frctl = frctl_init(argc, argv);// frctl in icerisi olabildigince dolduruldu. (renkler, kamera acisi...)
	if (frctl == NULL)
		return (-1);
	setup_mlx(frctl);
	fractol_loop(frctl);
	mlx_loop(frctl->mlx->ptr);
	return (0);
}

int	fractol_loop(t_fractol *frctl)// penceredeki pixellere renklerı yazdırmamızı sağlıyor
{
	size_t	x; // x eksenini 1000*1000 lik pencerede pixelini temsil eden değişken
	size_t	y; // y eksenini 1000*1000 lik pencerede pixelini temsil eden değişken

	// c.re -> 4*4 orandaki yerim (x icin)
	// c.im -> 4*4 orandaki yerim (y icin)
	frctl->scale.re = (frctl->c_max.re - frctl->c_min.re) / SIZE_X; // x in 4*4 luk sistemi 1000*1000 lik sisteme uyarlamamizi sagliyor. olceklendirmeyi sagiyor. Mesela haritayi burada 4 e boluyorum. koordinat sisteminin en solunun ust kosesinde -2,2 degerleri vardir. bu koordinat sistemindeki degerleri temsil eden degiskenler c.im ve c.re. 0 olarak verilen x ve y degerleri ise pixellerin konumunu belirtir. 0,0 noktasi sol en ustteki pixeldir. yani boylelikle kordinat isitemindeki 4*4 luk yerle, 1000*1000 lik pencereyi orantilamis oluyoruz
	frctl->scale.im = (frctl->c_max.im - frctl->c_min.im) / SIZE_Y; // y nin 4*4 luk sistemi 1000*1000 lik sisteme uyarlamamizi, orantilamamizi sagiyor
	y = 0; // 1000*1000 sistemin y sini 0dan baslatiyorum. saol ust kosenin ilk piskelinden basliyor
	while (y < SIZE_Y) 
	{
		frctl->c.im = frctl->c_max.im - y * frctl->scale.im; // 4*4 luk sistemin 2sinden basladigimizi gostermis oluyoruz. Gelen degerleri bu orana gore uyarlayip 4*4 luk sistemde karsiligini bulacagiz sonra da piksele basacagiz
		// y yi azaltiyorum cunku 2den -2 ye kadar azalmasi lazim
		x = 0;
		while (x < SIZE_X)
		{
			frctl->c.re = frctl->c_min.re + x * frctl->scale.re; // burada ise x e -2 atiyorum cunku 4*4 luk sistemin en sol tarafinin x degeri -2 oluyor
			frctl->fractal_func(frctl); // bu degerlegt ri fonksiyona gonderdik
			my_mlx_pixel_put(&frctl->mlx->img, x, y, get_color(frctl)); // renkleri basiyoruz
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frctl->mlx->ptr, frctl->mlx->win,
		frctl->mlx->img.ptr, 0, 0);// 0, 0 baslama noktasini belirledik
	return (0);
}
