/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:45:42 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/10 22:17:41 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	move_enemy(t_game	*game)
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
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == 'X')
			{
				move_enemy2(game, node->content, i, cnt);
				i++;
			}
			i++;
		}
		cnt++;
		node = node->next;
	}
	return (0);
}

int	move_enemy2(t_game *game, char *line, int i, int line_num)
{
	if (line[i + 1] == 'P')
		ft_close3(game);
	if (line[i + 1] == 'C')
		return (0);
	if (line[i + 1] == 'X')
		return (0);
	if (line[i + 1] == '1')
		return (0);
	if (line[i + 1] == 'E')
		return (0);
	line[i] = '0';
	line[i + 1] = 'X';
	draw_image(game, game->floor, i + 1, line_num);
	draw_image(game, game->enemy, i + 1, line_num);
	draw_image(game, game->floor, i, line_num);
	return (1);
}

int	move_enemyleft(t_game	*game)
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
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == 'X')
				move_enemyleft2(game, node->content, i, cnt);
			i++;
		}
		cnt++;
		node = node->next;
	}
	return (0);
}

int	move_enemyleft2(t_game *game, char *line, int i, int line_num)
{
	if (line[i - 1] == 'C')
		return (0);
	if (line[i - 1] == 'E')
		return (0);
	if (line[i - 1] == '1')
		return (0);
	if (line[i - 1] == 'X')
		return (0);
	if (line[i - 1] == 'P')
		ft_close3(game);
	line[i] = '0';
	line[i - 1] = 'X';
	draw_image(game, game->floor, i - 1, line_num);
	draw_image(game, game->enemy, i - 1, line_num);
	draw_image(game, game->floor, i, line_num);
	return (0);
}
