/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:51:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/10/13 17:27:19 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_coor set_pov(t_coor coor, char c)
{
	t_coor pov;

	if (c == 'N' || c == 'S')
	{
		pov.x = coor.x;
		if (c == 'N')
			pov.y = coor.y + 1;
		if (c == 'S')
			pov.y = coor.y - 1;
	}
	else
	{
		pov.y = coor.y;
		if (c == 'E')
			pov.x = coor.x + 1;
		if (c == 'W')
			pov.x = coor.x - 1;
	}
	return (pov);
}

int	check_player(t_data *data, char **map)
{
	int	x;
	int	y;
	int nb;
	
	nb = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				data->player.coor.x = x + 0.40;// put the player in the center of box
				data->player.coor.y = y + 0.40;
				data->player.direction = map[y][x];
				data->player.pov = set_pov(data->player.coor, map[y][x]);
				nb++;
			}
			x++;
		}
		y++;		
	}
	return (nb);
}
int	check_line(char *line, char *chars)
{
	int	i = 0;
	while (chars[i])
	{
		if (ft_strchr(line, chars[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_edges(char **map, int height, int width)
{
	int	i;

	i = 0;
	// if (check_line(map[0], '0') || ft_strchr(map[hight - 1], '0'))
	if (check_line(map[0], "NSWE0") || check_line(map[height - 1], "NSWE0"))
	{
		ft_strerr("0 in edges");
		exit(EXIT_FAILURE);
	}
	// printf("hereeee\n\n\n\n\n");
	while (i < height)
	{
		// if (map[i][0] == '0' || map[i][width - 1] == '0')
		if (ft_strchr("NSWE0", map[i][0]) || ft_strchr("NSWE0", map[i][width - 1]))
		{
			ft_strerr("0 in edges");
			exit(EXIT_FAILURE);
		}
		i++;	
	}
}
void	check_around(char **map, int x, int y)
{
	if (map[y - 1][x] == ' ' || map[y - 1][x] == ' ' || map[y - 1][x + 1] == ' ' || map[y][x - 1] == ' ' || map[y][x + 1] == ' ' || map[y + 1][x - 1] == ' ' || map[y + 1][x] == ' ' || map[y + 1][x + 1] == ' ')
	{
		ft_strerr("map is not surrounded by walls");
		exit(EXIT_FAILURE);
	}
}

void	check_all_map(char **map, int hight, int width)
{
	int	x;
	int	y;

	y = 1;
	while (y < hight - 1)
	{
		x = 1;
		while (x < width - 1)
		{
			if (map[y][x] == '0' || ft_strchr("NSWE", map[y][x]))
				check_around(map, x, y);
			x++;
		}
		y++;
	}
	
}
