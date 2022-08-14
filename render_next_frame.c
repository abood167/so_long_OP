/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:02:22 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/11 05:52:18 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_new_coin(t_game *game, int x, int y, int index)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->floor, x * 63, y * 63);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->col[index], x * 63, y * 63);
}

void	switch_coin(t_game *game)
{
	static int	index;
	char		*line;
	int			cnt;
	int			z;
	t_list		*map;

	map = game->map[game->mapnum];
	if (index >= 4)
		index = 0;
	cnt = 0;
	while (map != NULL)
	{
		z = 0;
		line = map->content;
		while (line[z] != '\0')
		{
			if (line[z] == 'C')
				draw_new_coin(game, z, cnt, index);
			++z;
		}
		cnt++;
		map = map->next;
	}
	index++;
}

int	render_next_frame(t_game	*game)
{
	static int	cnt;
	int			dir;

	cnt++;
	if (cnt == 5000)
	{
		switch_coin(game);
		cnt = 0;
	}
	if (cnt == 1000)
	{
		dir = rand() % 4;
		if (dir == 0)
			move_enemy(game);
		if (dir == 1)
			move_enemy_down(game);
		if (dir == 2)
			move_enemyleft(game);
		if (dir == 3)
			move_enemy_up(game);
	}
	return (0);
}

int	move_up_helper2(t_list **nodes, t_game *game, int i)
{
	if (((char *)(nodes[0]->content))[i] == 'E' && game->coins == 0)
	{
		if (game->mapnum == 3)
			ft_close2(game);
		nextmap(game);
	}
	if (((char *)(nodes[0]->content))[i] == 'E')
		return (game->steps-- && 0);
	if (((char *)(nodes[0]->content))[i] == '1')
	{
		game->steps--;
		return (0);
	}
	return (1);
}

int	move_down_helper2(t_list *node, t_game *game, int i)
{
	if (((char *)(node->next->content))[i] == 'E' && game->coins == 0)
	{
		if (game->mapnum == 3)
			ft_close2(game);
		nextmap(game);
	}
	if (((char *)(node->next->content))[i] == 'E')
		return (game->steps-- && 0);
	if (((char *)(node->next->content))[i] == '1')
	{
		game->steps--;
		return (0);
	}
	return (1);
}
