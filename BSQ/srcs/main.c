/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:22:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/27 11:16:46 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_map(char **tab, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	while (!(y < 0))
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}

void	ft_calls(char *argvn)
{
	char	**tab;
	char	*str;
	char	symb[4];
	int		y;
	int		x;

	str = gen_string(argvn);
	if (str == 0)
		return ;
	y = 0;
	x = 0;
	if (ft_check_file(str, symb, &y, &x) == 0)
	{
		free (str);
		write(2, "map error\n", 10);
		return ;
	}
	only_map(str);
	tab = ft_split(str, y, x);
	if (tab == 0)
		return ;
	ft_print_map(ft_call_bsq(tab, y, x, symb), x, y);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		if (gen_file() == 0)
			return (1);
		ft_calls(".user_input");
	}
	else
	{
		while (i < argc)
		{
			if (i > 1)
				ft_putchar('\n');
			ft_calls(argv[i++]);
		}
	}
}
