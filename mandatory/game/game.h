/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:31:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/08 17:05:23 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../cub3D.h"

void	init_mlx_elements(t_data *data);
void	my_mlx_put_pixel(t_data *data, mlx_image_t *img,
			t_coor coor, u_int32_t color);
int		get_rgba(int r, int g, int b, int a);
void	draw_player(t_data *data, t_coor coor, mlx_image_t *img);

double	ft_normalizer(double angle);
int		gett_rgba(uint8_t *color);

void	cast_ray(t_data *data, double angle, int i);
t_coor	first_h_inter(double angle, t_coor player);
t_coor	first_v_inter(double angle, t_coor player);
void	ft_horizontal(t_coor *hit, double angle);
void	ft_vertical(t_coor *hit, double angle);
t_coor	ft_compare(t_coor player, t_coor h, t_coor v, t_ray *ray);

void	draw_columns(t_data *data, t_ray *ray, double angle);
void	render_background(t_data *data);

#endif
