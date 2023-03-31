/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:56:13 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/26 14:13:16 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_color(t_fractol *frctl, size_t i);

int	get_color(t_fractol *frctl)
{
	return (frctl->color_scheme[frctl->iter]);
}

void	set_color_array(t_fractol *frctl)
{
    // terminali actigimizda max_iter kadar renk cikmasini saglayan fonksiyondur.
	size_t	i;

	i = 0;
	while (i <= frctl->max_iter) //25
	{
		frctl->color_scheme[i] = calc_color(frctl, i);// indexe gelen rengi atadik
		i++;
        // --------- max_iter = 2 yap. aslinda bu yesil rengini ekrana yazdirmak icin calc_color'u kullaniyoruz.
        // --------- eger daha fazla renk varsa uyumu saglamak icin bunlari color_sheme'e atiyoruz.
	}
}

static int	calc_color(t_fractol *frctl, size_t i)
{
	uint8_t	chng; // uint8 -> unsigned char. normalde ascii 127 ye kadardir. ama unsogned olunca 255 olur.
	uint8_t	rgb[3];
	double	hop;

	chng = frctl->color_shift;  // color_shift'e helper'daki frctl_init fonskiyonunda 0 atanmisti. bu renk degıstırmek ıcın kullanılıyor
    hop = (double) i / frctl->max_iter;// max_iter = 50
	if (frctl->color_shift < 3)
	{
		rgb[chng % 3] = 9 * (1 - hop) * pow(hop, 2) * 255;
		rgb[(chng + 1) % 3] = 15 * pow((1 - hop), 42) * pow(hop, 2) * 255;
		rgb[(chng + 2) % 3] = 9 * pow((1 - hop), 91) * hop * 255;
	}//blue -> red -> green
    else// color_shifti 3 ten fazla degistirirsek
	{
		rgb[chng % 3] = 9 * pow((1 - hop), 3) * hop * 255;
		rgb[(chng + 1) % 3] = 15 * pow((1 - hop), 2) * pow(hop, 2) * 255;
		rgb[(chng + 2) % 3] = 9 * (1 - hop) * pow(hop, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);// neden farkli rgb degerlerinin bitlerini kaydirdik?
}
// 32 bit in ilk 8 bitini en sola kaydiriyoruz. sonraki kaydirmalari yapinca artik, ilk bastaki bos oluyor temizlemis oluyoruz, bir sonraki red, bir sonraki green, bir sonraki blue oluyor.
// ve aldiklari degere gore renk gecisi oluyor.
//     00000000        000000000        00000000        11111111

