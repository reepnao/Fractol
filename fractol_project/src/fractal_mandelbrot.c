/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:00:30 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/29 01:01:29 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 8) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}
