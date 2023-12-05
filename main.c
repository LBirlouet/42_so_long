/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/05 10:52:32 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_back(t_map *t_map)
{
	void	*mlx;
	int		verif;
	void	*mlx_win;
	char	*relative_path_back;
	char	*relative_path_back2;
	char	*relative_path_back3;
	char	*relative_path_back4;
	int		img_width;
	int		img_height;
	t_data	img;
	
	int x = 0;
	int y = 0;
	printf("larg%d\nlong%d\n", t_map->map_x, t_map->map_y);
	relative_path_back = "./img/fond.xpm";
	relative_path_back2 = "./img/fond2.xpm";
	relative_path_back3 = "./img/fond3.xpm";
	relative_path_back4 = "./img/fond4.xpm";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (t_map->map_x * 32), ((t_map->map_y + 1) * 32), "so_long");

	img.imgback = mlx_new_image(mlx, (t_map->map_x * 32), (t_map->map_y * 32));
	img.imgbackr = mlx_new_image(mlx, (t_map->map_x * 32), (t_map->map_y * 32));
	img.imgbackrr = mlx_new_image(mlx, (t_map->map_x * 32), (t_map->map_y * 32));
	img.imgbackrrr = mlx_new_image(mlx, (t_map->map_x * 32), (t_map->map_y * 32));

	img.addr = mlx_get_data_addr(img.imgback, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.imgback =  mlx_xpm_file_to_image(mlx, relative_path_back, &img_width, &img_height);
	img.imgbackr =  mlx_xpm_file_to_image(mlx, relative_path_back2, &img_width, &img_height);
	img.imgbackrr =  mlx_xpm_file_to_image(mlx, relative_path_back3, &img_width, &img_height);
	printf("avat : img.imgbackrr %p \n", img.imgbackrr);
	img.imgbackrrr =  mlx_xpm_file_to_image(mlx, relative_path_back4, &img_width, &img_height);

	while (y <= (t_map->map_y * 32))
	{
		x = 0;
		while (x <= (t_map->map_x * 32))
		{
//			printf("X DE tES MORTS%d diviser modulo %d\n", x, ((x / 32) % 4));
			if ((x % 32 == 0) && ((x / 32)%4 == 0))
				mlx_put_image_to_window(mlx, mlx_win, img.imgback, x, y);
			else if ((x % 32 == 0) && ((x / 32)%4 == 1))
				mlx_put_image_to_window(mlx, mlx_win, img.imgbackr, x, y);
			else if ((x% 32 == 0) && ((x / 32) %4 == 2))
				mlx_put_image_to_window(mlx, mlx_win, img.imgbackrr, x, y);
			else
				mlx_put_image_to_window(mlx, mlx_win, img.imgbackrrr, x, y);

			x += 32;
		}
		y += 32;
	}
	verif = display_wall(t_map, mlx, &img, mlx_win);
	mlx_loop(mlx);
	return (0);
}

int	display_wall(t_map *t_map, void *mlx, t_data *img, void *mlx_win)
{
	char	*relative_path_wall;
	char	*line;
	int		img_width;
	int		img_height;
	int		x = 0;
	int		y = 0;
	int		i;

	relative_path_wall = "./img/wall.xpm";
	img->imgwall = mlx_new_image(mlx, (t_map->map_x * 32), (t_map->map_x * 32));
	printf("ici + %p\n", img->imgwall);
	img->imgwall = mlx_xpm_file_to_image(mlx, relative_path_wall, &img_width, &img_height);
	printf("%p | %p | %p\n", mlx, mlx_win, img->imgwall);
	int fd = open(t_map->map_name, O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("ahg\n");
		return (1);
	}
	while (y <= t_map->map_y)
	{
		printf("%d\n", y);
		i = 0;
		x = 0;
		line = get_next_line(fd);
		printf("%s\n", line);
		while (line[i] != '\n' && line[i] != 0)
		{
			if (line[i] == '1')
			{	
			mlx_put_image_to_window(mlx, mlx_win, img->imgwall, (x * 32), (y * 32));
			}
			x++;
			i++;
		}
		free(line);
		y++;
	}
	close(fd);
	return (0);
}


int main()
{
	t_map	t_map;

	t_map.map_name = "map1";	
	t_map.map_fd = open(t_map.map_name, O_RDONLY, 0644);

	if (t_map.map_fd == -1)
	{
		printf("ahg\n");
		return (1);
	}
	int verif = verif_map(t_map.map_fd, &t_map, t_map.map_name);
	printf("%d\n", verif);
	if (verif == -1)
		return (-1);

//	x = ft_strlen(line);

	
	//printf("%s", line);
	// while (line)
	// {
	// 	free(line);
	// 	line = get_next_line(fd);
	// 	printf("%s", line);
	// }

	// if (verif_map(char *map) == 0)
	// 	return (0);
//	printf("%d\n", t_map.map_x);

	verif = display_back(&t_map);
	if (verif == -1)
		return (-1);
	return (0);
}