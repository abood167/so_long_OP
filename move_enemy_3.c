/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:48:27 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/11 06:29:46 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_enemy_down(t_game	*game)
{
	char	*line;
	t_list	*node;
	int		cnt;
	int		i;

	node = game->map[game->mapnum];
	cnt = 0;
	while (node != NULL)
	{
		line = node->content;
		i = -1;
		while (line[++i])
			if (line[i] == 'X')
				move_enemy_down_h(node, game, i, cnt);
		cnt++;
		node = node->next;
	}
	return (1);
}

int	move_enemy_down_h(t_list *node, t_game *game, int i, int cnt)
{
	if (((char *)(node->next->content))[i] == 'C')
		return (0);
	if (((char *)(node->next->content))[i] == 'P')
		ft_close3(game);
	if (((char *)(node->next->content))[i] == 'X')
		return (0);
	if (move_enemy_down_h2(node, i) == 0)
		return (0);
	if (node->next == NULL)
		return (0);
	((char *)(node->content))[i] = '0';
	((char *)(node->next->content))[i] = 'X';
	draw_image(game, game->floor, i, cnt + 1);
	draw_image(game, game->enemy, i, cnt + 1);
	draw_image(game, game->floor, i, cnt);
	return (0);
}

int	move_enemy_down_h2(t_list *node, int i)
{
	if (((char *)(node->next->content))[i] == 'E')
		return (0);
	if (((char *)(node->next->content))[i] == '1')
	{
		return (0);
	}
	return (1);
}
