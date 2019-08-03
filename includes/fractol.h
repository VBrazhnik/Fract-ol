/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:13:40 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/07/31 19:48:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000

# define THREADS	10

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdint.h>

/*
** Color
*/

/*
** channel — alpha, red, green, blue color channels
*/

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

/*
** Image
*/

/*
** image          — image identifier
** data_addr      — image
** bits_per_pixel — depth of image
** size_line      — number of bytes used to store one line of image
** endian         — little or big endian
*/

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

/*
** Fract'ol
*/

/*
** mlx            — connection identifier
** window         — window identifier
** image          — information about image
** max_iteration  — maximum iteration
** min            — minimum real and imaginary parts of complex numbers
** max            — maximum real and imaginary parts of complex numbers
** factor         — dependency between complex numbers and pixels
** c              — complex number
** k              — constant complex number (only for Julia)
** is_julia_fixed — flag that reports Julia is fixed or is not
** start_line     — start line of fractal part (needed for multi-threading)
** finish_line    — finish line of fractal part (needed for multi-threading)
** color_shift    — shift of color channels
** formula        — fractal formula
** is_help        — flag that reports help screen is displayed or is not
*/

typedef struct		s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	t_bool			is_julia_fixed;
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
	t_bool			is_help;
}					t_fractol;

/*
** Formula
*/

/*
** name    — name of fractal
** formula — formula of fractal
*/

typedef struct		s_formula
{
	char			*name;
	int				(*formula)(t_fractol *fractol);
}					t_formula;

/*
** Functions
*/

/*
** Init
*/

t_image				*init_image(void *mlx);

t_complex			init_complex(double re, double im);

void				set_defaults(t_fractol *fractol);

/*
** Draw
*/

void				draw_fractal(t_fractol *fractol);

void				draw_help(t_fractol *fractol);

/*
** Fractals
*/

int					iterate_mandelbrot(t_fractol *fractol);

int					iterate_julia(t_fractol *fractol);

int					iterate_burning_ship(t_fractol *fractol);

int					iterate_mandelbar(t_fractol *fractol);

int					iterate_celtic_mandelbrot(t_fractol *fractol);

int					iterate_celtic_mandelbar(t_fractol *fractol);

int					iterate_celtic_perpendicular(t_fractol *fractol);

int					iterate_perpendicular_mandelbrot(t_fractol *fractol);

int					iterate_perpendicular_burning_ship(t_fractol *fractol);

int					iterate_perpendicular_buffalo(t_fractol *fractol);

/*
** Color
*/

t_color				get_color(int iteration, t_fractol *fractol);

/*
** Controls
*/

int					close(void *param);

int					key_press(int key, t_fractol *fractol);

int					zoom(int button, int x, int y, t_fractol *fractol);

int					julia_motion(int x, int y, t_fractol *fractol);

/*
** Print
*/

void				print_help(void);

/*
** Utils
*/

void				terminate(char *s);

#endif
