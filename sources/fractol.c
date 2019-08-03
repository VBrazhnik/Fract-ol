/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:11:22 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/07/29 20:45:42 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_message.h"

static int			(*get_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot },
		{ "Julia", &iterate_julia },
		{ "Burning Ship", &iterate_burning_ship },
		{ "Mandelbar", &iterate_mandelbar },
		{ "Celtic Mandelbrot", &iterate_celtic_mandelbrot },
		{ "Celtic Mandelbar", &iterate_celtic_mandelbar },
		{ "Celtic Perpendicular", &iterate_celtic_perpendicular },
		{ "Perpendicular Mandelbrot", &iterate_perpendicular_mandelbrot },
		{ "Perpendicular Burning Ship", &iterate_perpendicular_burning_ship },
		{ "Perpendicular Buffalo", &iterate_perpendicular_buffalo }
	};

	i = 0;
	formula = NULL;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (ft_strequ(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		terminate(ERR_FRACTOL_INIT);
	fractol->mlx = mlx;
	if (!(fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name)))
		terminate(ERR_WINDOW_INIT);
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	fractol->is_julia_fixed = true;
	if (!(fractol->formula = get_formula(name)))
		terminate(ERR_FRACTAL_NAME);
	fractol->is_help = false;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
	return (fractol);
}

static void			start(int number, char **names)
{
	t_fractol	*fractols[10];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	while (i < number)
	{
		fractols[i] = init_fractol(names[i], mlx);
		draw_fractal(fractols[i]);
		i++;
	}
	mlx_loop(mlx);
}

int					main(int argc, char **argv)
{
	int	i;

	if (argc >= 2 && argc <= 11)
	{
		i = 1;
		while (i < argc)
		{
			if (!get_formula(argv[i]))
				break ;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
	print_help();
	return (0);
}
