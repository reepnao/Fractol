/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_celtic_mandelbrot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:56:07 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/26 14:12:54 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	celtic_mandelbrot(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = fabs(tmp.re - tmp.im) + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}
