/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:57:09 by jsabound          #+#    #+#             */
/*   Updated: 2022/07/09 18:35:10 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	f_print_hyphen(int i, int x)
{
	while (i < x - 2)
	{
		ft_putchar('*');
		i++;
	}
}

void	f_print_pipe(int i, int j, int x, int y)
{
	while (i < y - 2)
	{
		ft_putchar('*');
		j = 0;
		while (j < x - 2)
		{
			ft_putchar(' ');
			j++;
		}
		if (x > 1)
			ft_putchar('*');
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putchar('/');
	f_print_hyphen(i, x);
	if (x > 1)
		ft_putchar('\\');
	ft_putchar('\n');
	f_print_pipe(i, j, x, y);
	if (y > 1)
	{
		ft_putchar('\\');
		f_print_hyphen(i, x);
		if (x > 1)
			ft_putchar('/');
		ft_putchar('\n');
	}
}
