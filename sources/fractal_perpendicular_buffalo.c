/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_perpendicular_buffalo.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:55:28 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/07/06 19:17:12 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		iterate_perpendicular_buffalo(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->c.re,
			-2.0 * z.re * fabs(z.im) + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
