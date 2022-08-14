/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:41:24 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/11 05:55:22 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_enemy_up(t_game	*game)
{
	char	*line;
	t_list	*nodes[2];
	int		cnt;
	int		i;

	nodes[0] = NULL;
	nodes[1] = game->map[game->mapnum];
	cnt = 0;
	while (nodes[1] != NULL)
	{
		line = nodes[1]->content;
		i = 0;
		while (line[i])
		{
			if (line[i] == 'X')
				move_enemy_up_helper(nodes, game, i, cnt);
			i++;
		}
		cnt++;
		nodes[0] = nodes[1];
		nodes[1] = nodes[1]->next;
	}
	return (0);
}

int	move_enemy_up_helper(t_list **nodes, t_game *game, int i, int cnt)
{
	if (((char *)(nodes[0]->content))[i] == 'P')
		ft_close3(game);
	if (((char *)(nodes[0]->content))[i] == 'C')
		return (0);
	if (((char *)(nodes[0]->content))[i] == 'E')
		return (0);
	if (((char *)(nodes[0]->content))[i] == 'X')
		return (0);
	if (move_enemy_up_helper2(nodes, i) == 0)
		return (0);
	if (nodes[0] == NULL)
		return (0);
	((char *)(nodes[1]->content))[i] = '0';
	((char *)(nodes[0]->content))[i] = 'X';
	draw_image(game, game->floor, i, cnt - 1);
	draw_image(game, game->enemy, i, cnt - 1);
	draw_image(game, game->floor, i, cnt);
	return (0);
}

int	move_enemy_up_helper2(t_list **nodes, int i)
{
	if (((char *)(nodes[0]->content))[i] == 'E')
		return (0);
	if (((char *)(nodes[0]->content))[i] == '1')
	{
		return (0);
	}
	return (1);
}
