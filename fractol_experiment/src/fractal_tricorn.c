/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tricorn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:10:40 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/27 13:22:06 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int tricorn(t_fractol *frctl, double x, double y)
{
    double re = 0;
    double im = 0;
    double re2 = 0;
    double im2 = 0;
    size_t i = 0;

    while (re2 + im2 <= 4 && i < frctl->max_iter)
    {
        im = -2 * re * im + y;
        re = re2 - im2 + x;
        re2 = re * re;
        im2 = im * im;
        i++;
    }

    if (i == frctl->max_iter)
        return (0);
    else
        return (i % frctl->color_depth);
}