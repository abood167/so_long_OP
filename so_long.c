/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:35:21 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/11 01:01:37 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game	*game)
{
	ft_printf("nice for playing");
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mapsname[0]);
	free(game->mapsname[1]);
	free(game->mapsname[2]);
	free(game->mapsname[3]);
	ft_lstclear (&game->map[0], free);
	ft_lstclear (&game->map[1], free);
	ft_lstclear (&game->map[2], free);
	ft_lstclear (&game->map[3], free);
	mlx_destroy_image(game->mlx, game->img);
	exit(1);
}

int	ft_close3(t_game	*game)
{
	ft_printf(KRED"you dead(-_-)"KNRM);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mapsname[0]);
	free(game->mapsname[1]);
	free(game->mapsname[2]);
	free(game->mapsname[3]);
	ft_lstclear (&game->map[0], free);
	ft_lstclear (&game->map[1], free);
	ft_lstclear (&game->map[2], free);
	ft_lstclear (&game->map[3], free);
	mlx_destroy_image(game->mlx, game->img);
	exit(1);
}

int	ft_close2(t_game	*game)
{
	ft_printf(KRED"Moves = %d\n"KNRM, game->steps);
	ft_printf(KYEL"you have done %d of MOVES!\n"KNRM, game->steps);
	ft_printf("game over ;)");
	ft_lstclear (&game->map[0], free);
	ft_lstclear (&game->map[1], free);
	ft_lstclear (&game->map[2], free);
	ft_lstclear (&game->map[3], free);
	free(game->mapsname[0]);
	free(game->mapsname[1]);
	free(game->mapsname[2]);
	free(game->mapsname[3]);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 5)
	{
		ft_putstr("error argumant : should  be like  ./so_long maps/map1.ber \
		maps/map2.ber maps/map3.ber maps/map4.ber ");
		return (1);
	}
	init_map(&game, av);
	game.mlx_win = mlx_new_window(game.mlx,
			ft_strlen((char *)game.map[game.mapnum]->content) * 64,
			ft_lstsize(game.map[game.mapnum]) * 64, game.mapsname[0]);
	game.img = mlx_new_image(game.mlx,
			ft_strlen((char *)game.map[game.mapnum]->content)
			* 64, ft_strlen((char *)game.map[game.mapnum]->content) * 64);
	draw_map(&game);
	mlx_hook(game.mlx_win, 17, 0, ft_close, &game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
}
