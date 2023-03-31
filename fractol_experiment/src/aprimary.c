/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprimary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:56:15 by rbattal           #+#    #+#             */
/*   Updated: 2023/03/26 14:13:28 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*frctl_init(int argc, char **argv)
{
	t_fractol	*frctl;

	frctl = malloc(sizeof(t_fractol));
	if (frctl == 0)
		return (0);
	frctl->color_scheme = malloc((500 + 1) * sizeof(int));
	if (frctl->color_scheme == 0)
		free_kill_all(frctl);
	frctl->mlx = NULL;
	frctl->color_shift = 0;
	set_pov(frctl);//goruntudeki iteration sayisinin birbirini izlemesini sagladik. renk degisimlerini rastgele olmasini sagladik.renk secimlerinin(color_shift) rasgele olmasini sagladik.
    which_func(argc, argv, frctl);// hangi  haritayi  kullanacagimizi gosterdik (julia, mandelbrot...)
	return (frctl);// artik icerisi doldurulmus frctl geri donduruldu
    
}

int	set_pov(t_fractol *frctl)// goruntunun orantili olmasini sagladik. buyudukce bozulmamasini sagladik.
{
	frctl->max_iter = 25;
	frctl->is_fixed = true;
	if (SIZE_X == SIZE_Y)
	{
		complex_set(&frctl->c_max, 2, 2);
        // 2. paramtre -> kuculdukce x genisler.
        // 3. paramtrre -> yukari asagi hareket ettirir.(buyutunce asagi, kuculttukce yukari cikar.)
		complex_set(&frctl->c_min, -2, -2);
        // 2. parametre -> yukari asagi kaydirir.
        // 3. parametre -> sag-sol kaydirir.
    }
	else
	{
		complex_set(&frctl->c_min, -2, -2);
		frctl->c_max.im = 2;
		frctl->c_min.re = (SIZE_X / SIZE_Y
				* (frctl->c_max.im - frctl->c_min.im)
				+ frctl->c_min.re);
        // bunu coz? neden c_minde yapmadik da c_maxda yaptik?
        // buraya hesaplayip da sabit sayi vermememizin sebebi, buyuttukce bu degeri tekrar tekrar hesaplamasi ve oranin bozulmamasidir.
	}
	complex_set(&frctl->c_julia, -0.6, 0.6);
	set_color_array(frctl);// goruntunun max_iter'e kadar renk almasini sagladik.
	return (0);
}

void	which_func(int argc, char **argv, t_fractol *frctl)
{
	frctl->fractal_func = NULL;
	if ((argc == 2 || argc == 4) && !ft_strncmp(argv[1], "julia", 6))
	{
		frctl->fractal_func = julia; // bu  hareketi yapar tum struct yapilarimin julaya gore calismasini sagliyorum
		if (argc == 4)
		{
			frctl->c_julia.re = ft_atoi(argv[2]);
			frctl->c_julia.im = ft_atoi(argv[3]);
		}
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		frctl->fractal_func = mandelbrot;
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 9))
		frctl->fractal_func = burning_ship;
	else if (argc == 2 && !ft_strncmp(argv[1], "celtic_mandelbrot", 9))
		frctl->fractal_func = celtic_mandelbrot;
	else
		printf_warning();
	if (frctl->fractal_func == NULL)
		free_kill_all(frctl);
}

int	free_kill_all(t_fractol *frctl)
{
	if (frctl->mlx != NULL)
	{
		mlx_destroy_image(frctl->mlx->ptr, frctl->mlx->img.ptr);
		mlx_destroy_window(frctl->mlx->ptr, frctl->mlx->win);
		free(frctl->mlx);
	}
	free(frctl->color_scheme);
	free(frctl);
	exit(0);
}
