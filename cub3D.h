/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:40 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/15 10:19:36 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

/*------------------------[ includes ]----------------------------------*/

#include <unistd.h>//
#include <stdio.h> // for testing
#include <fcntl.h>
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "src/libft/libft.h"


#define BOX  32
#define BOXE  32
#define	PI 3.14159265359
#define RAD PI / 180 // one radian
#define DEGREE 0.174533
#define	SPEED 5

/*------------------------[ structs ]----------------------------------*/

typedef struct s_coor
{
	double	x;	
	double	y;
	
}	t_coor;

typedef struct s_player
{
	t_coor		coor;// coordinates of player with pixels
	double		angle;// angle of player 
	
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width; // width of map
	int		heigth;// height of map
	mlx_image_t *img;// image of map
}	t_map;

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
} t_rgb;

typedef struct s_color
{
	t_rgb		F;
	t_rgb		C;
	u_int16_t	flag;
} t_color;

typedef struct s_texture
{
	char		*NO;
	char		*SO;
	char		*EA;
	char		*WE;
	u_int16_t	flag;
} t_texture;

typedef	struct s_ray
{
	t_coor		hit_point;
	u_int32_t	distance;
	
}	t_ray;

typedef struct s_data
{
	t_list		*file_content;// content from map's file
	t_map		map;// struct of infos of map
	t_texture	textures;// textures from file
	t_color		colors;// colors from file
	int		 	header_end; // when I finish to extract colors and colors i pust this flag to it
	t_player	player; // player information
	mlx_t		*mlx;// mlx variable
	mlx_image_t	*ft_3D;// image of 3d vue
	mlx_key_data_t keys; // key hooks
	
	
}	t_data;



/*------------------------[ prototypes ]-------------------------------*/

/*--[ :: parsing :: ]--*/

void	check_requirements(int ac, char **av, t_data *data);
void	mini_map(t_data *data);
void	my_mlx_put_pixel(t_data *data, t_coor coor, u_int32_t color);

/*--[ :: raycasting :: ]--*/

void	ft_loop(void *dataa);// loop hook

#endif
