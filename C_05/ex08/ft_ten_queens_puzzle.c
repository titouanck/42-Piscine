/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:21:05 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/24 12:05:17 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_pos(char map[10][10], int y, int x)
{
	int	i;

	i = -1;
	while (++i < 10)
		if (map[i][x] == 'Q' || map[y][i] == 'Q' || map[y][x] == 'a')
			return (0);
	i = -1;
	while (x + ++i < 10 && y + i < 10)
		if (map[y + i][x + i] == 'Q')
			return (0);
	i = -1;
	while (x - ++i >= 0 && y - i >= 0)
		if (map[y - i][x - i] == 'Q')
			return (0);
	i = -1;
	while (x + ++i < 10 && y - i >= 0)
		if (map[y - i][x + i] == 'Q')
			return (0);
	i = -1;
	while (x - ++i >= 0 && y + i < 10)
		if (map[y + i][x - i] == 'Q')
			return (0);
	return (1);
}

void	ft_print_map(char map[10][10], char *p_nbr)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			if (map[j][i] == 'Q')
				write(1, &p_nbr[j], 1);
	}
	write(1, "\n", 1);
}

int	ft_reset_map(char map[10][10], int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		if (x >= 0)
		{
			if (map[i][x] == 'Q')
				y = i;
		}
		else
		{
			j = -1;
			while (++j < 10)
				if (map[i][j] != 'a')
					map[i][j] = 'x';
		}
	}
	i = -1;
	while (++i < 10 && x >= 0 && x < 10)
		if (map[i][x] != 'a')
			map[i][x] = 'x';
	return (y);
}

int	ft_put_queens(char map[10][10], int y, int x, int a)
{
	if (!(x < 10))
		return (y);
	if (ft_check_pos(map, y, x))
	{
		map[y][x] = 'Q';
		if (a > -1 && map[a][9] == 'a')
			map[a][9] = 'x';
		if (++x < 10)
			y = 0;
		return (ft_put_queens(map, y, x, a));
	}
	else if (y < 9)
		return (ft_put_queens(map, y + 1, x, a));
	else
	{
		y = ft_reset_map(map, x - 1, -69);
		if (y < 9)
			return (ft_put_queens(map, y + 1, x - 1, a));
		else
		{
			y = ft_reset_map(map, x - 2, -69);
			return (ft_put_queens(map, y + 1, x - 2, a));
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		a;
	int		i;
	char	map[10][10];

	ft_reset_map(map, -1, -69);
	a = ft_put_queens(map, 0, 0, -69);
	i = 1;
	while (!(map[9][0] == 'Q' && map[7][1] == 'Q'
	&& map[4][2] == 'Q' && map[2][3] == 'Q'))
	{
		ft_print_map(map, "0123456789");
		map[a][9] = 'a';
		a = ft_put_queens(map, 0, 9, a);
		i++;
	}
	ft_print_map(map, "0123456789");
	return (i);
}
