/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:07:27 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:07:28 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_map(t_fill *game)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strstr(line, "==") != NULL)
	{
		ft_strdel(&line);
		exit(0);
	}
	line = line + 8;
	game->map_size[0] = ft_atoi(line);
	while (*line != 32)
		line++;
	game->map_size[1] = ft_atoi(line);
	//ft_printf("Map Size:[%i][%i]", game->map_size[0], game->map_size[1]);
	ft_strdel(&line);
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
}

void		read_bit(t_fill *game)
{
	int		a;
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	line += 6;
	game->bit_size[0] = ft_atoi(line);
	while (*line != 32)
		line++;
	game->bit_size[1] = ft_atoi(line);
	if (game->bit != NULL)
		ft_free_arr(game->bit);
	game->bit = (char**)malloc((sizeof(char*) * game->bit_size[0]) + 1);
	game->bit[game->bit_size[0]] = NULL;
	a = 0;
	while (a < game->bit_size[0])
	{
		get_next_line(STDIN_FILENO, &line);
		game->bit[a] = ft_strdup(line);
		ft_strdel(&line);
		a++;
	}
}

void	read_map(t_fill *game)
{

	int		a;
	char	*line;

	if (game->map != NULL)
		ft_free_arr(game->map);
	check_map(game);
	game->map = (char**)malloc((sizeof(char*) * game->map_size[0]) + 1);
	game->map[game->map_size[0]] = NULL;
	a = 0;
	while (a < game->map_size[0])
	{
		get_next_line(STDIN_FILENO, &line);
		game->map[a] = ft_strdup(line + 4);
		ft_strdel(&line);
		a++;
	}
}

void	start_play(t_fill *game)
{
	read_map(game);
	if (game->xo == 'O')
	{
		read_bit(game);
		spot_loc(game);
		wait_enemy(game);
		read_map(game);
	}
	else
	{
		wait_enemy(game);
		read_map(game);
	}
	while (1)
	{
		read_bit(game);
		spot_loc(game);
		wait_enemy(game);
		read_map(game);
	}
}

void	start_filler(void)
{
	char	*line;
	t_fill	*game;

	game = (t_fill*)malloc(sizeof(t_fill));
	get_next_line(STDIN_FILENO, &line);
	game->xo = 'X';
	game->enemy = 'O';
	if (ft_strstr(line, "./filler") != NULL)
	{
		game->xo = 'O';
		game->enemy = 'X';
	}
	//ft_printf("My symbol:%c\n", game->xo);
	ft_strdel(&line);
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	start_play(game);
}

int		main(int argc, char **argv)
{
	if (argc > 0 && *argv)
	{
		ft_printf("My Filler.\n");
		start_filler();
		return (0);
	}
	return (0);
}
