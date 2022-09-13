/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:22:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/27 12:17:10 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	ft_find_max_tab(int **tab, int *x, int *y)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	i = -1;
	posx = 0;
	posy = 0;
	while (++i < *y)
	{
		j = -1;
		while (++j < *x)
		{
			if (tab[i][j] > tab[posy][posx])
			{
				posx = j;
				posy = i;
			}
		}
	}
	*x = posx;
	*y = posy;
	return (tab[*y][*x]);
}

void	ft_mapping(int **tab, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i < y)
	{
		j = 1;
		while (j < x)
		{
			if (tab[i][j] == 1)
			{
				tab[i][j] = ft_min(tab[i - 1][j - 1], tab[i][j - 1],
						tab[i - 1][j]) + 1;
			}
			j++;
		}
		i++;
	}
}

void	free_int_tab(int **int_tab, int y)
{
	while (y >= 1)
		free(int_tab[--y]);
	free(int_tab);
}

char	**ft_call_bsq(char **tab, int y, int x, char *symb)
{
	int	**int_tab;
	int	n;
	int	i;
	int	j;
	int	y_alias;

	y_alias = y;
	if (x < 2)
		int_tab = convert_from(tab, symb, 2, y);
	else
		int_tab = convert_from(tab, symb, x, y);
	ft_mapping(int_tab, x, y);
	n = ft_find_max_tab(int_tab, &x, &y);
	i = 0;
	j = 0;
	i = y + 1;
	while (--i > y - n)
	{
		j = x + 1;
		while (--j > x - n)
			tab[i][j] = symb[2];
	}
	free_int_tab(int_tab, y_alias);
	return (tab);
}
