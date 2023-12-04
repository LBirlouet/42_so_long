/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/04 19:23:01 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_back(int largeur, int longueur)
{
	void	*mlx;
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
	relative_path_back = "./img/fond.xpm";
	relative_path_back2 = "./img/fond2.xpm";
	relative_path_back3 = "./img/fond3.xpm";
	relative_path_back4 = "./img/fond4.xpm";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (largeur * 32), (longueur * 32), "Houui");

	img.imgback = mlx_new_image(mlx, (largeur * 32), (longueur * 32));
	img.imgbackr = mlx_new_image(mlx, (largeur * 32), (longueur * 32));
	img.imgbackrr = mlx_new_image(mlx, (largeur * 32), (longueur * 32));
	img.imgbackrrr = mlx_new_image(mlx, (largeur * 32), (longueur * 32));

	img.addr = mlx_get_data_addr(img.imgback, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.imgback =  mlx_xpm_file_to_image(mlx, relative_path_back, &img_width, &img_height);
	img.imgbackr =  mlx_xpm_file_to_image(mlx, relative_path_back2, &img_width, &img_height);
	img.imgbackrr =  mlx_xpm_file_to_image(mlx, relative_path_back3, &img_width, &img_height);
	img.imgbackrrr =  mlx_xpm_file_to_image(mlx, relative_path_back4, &img_width, &img_height);

	while (y <= (longueur * 32))
	{
		x = 0;
		while (x <= (largeur * 32))
		{
			printf("X DE tES MORTS%d diviser modulo %d\n", x, ((x / 32) % 4));
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

	mlx_loop(mlx);
}


int main()
{
	t_map	t_map;
	char *map_name;

	map_name = "map1";	
	int fd = open(map_name, O_RDONLY, 0644);

	if (fd == -1)
	{
		printf("ahg\n");
		return (1);
	}
	int verif = verif_map(fd, &t_map, map_name);
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

	printf("%d\n", t_map.map_x);
	display_back(t_map.map_x, t_map.map_y);
	return (0);
}