/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:30:17 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/11 06:51:12 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	nextmap(t_game	*game)
{
	game->mapnum++;
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img);
	game->mlx_win = mlx_new_window(game->mlx,
			ft_strlen((char *)game->map[game->mapnum]->content) * 63,
			ft_lstsize(game->map[game->mapnum]) * 63,
			game->mapsname[game->mapnum]);
	game->img = mlx_new_image(game->mlx,
			ft_strlen((char *)game->map[game->mapnum]->content)
			* 63, ft_strlen((char *)game->map[game->mapnum]->content) * 63);
	draw_map(game);
	mlx_hook(game->mlx_win, 17, 0, ft_close, game);
	mlx_hook(game->mlx_win, 2, 0, key_hook, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
}

void	init_map(t_game *game, char **av)
{
	game->steps = 0;
	game->face = 0;
	game->mlx = mlx_init();
	game->mapsname[0] = ft_strdup("so_long map1");
	game->mapsname[1] = ft_strdup("so_long map2");
	game->mapsname[2] = ft_strdup("so_long map3");
	game->mapsname[3] = ft_strdup("so_long map4");
	game->map[0] = read_map (av[1]);
	game->map[1] = read_map (av[2]);
	game->map[2] = read_map (av[3]);
	game->map[3] = read_map (av[4]);
	game->mapnum = 0;
	finel_check(game->map[0]);
	finel_check(game->map[1]);
	finel_check(game->map[2]);
	finel_check(game->map[3]);
}
