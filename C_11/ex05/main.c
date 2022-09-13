/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:09:37 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/23 22:24:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_ft(void (*f[6])(int, int), char sign, int a, int b)
{
	if (sign == '+')
		f[0](a, b);
	else if (sign == '-')
		f[1](a, b);
	else if (sign == '/')
		f[2](a, b);
	else if (sign == '*')
		f[3](a, b);
	else if (sign == '%')
		f[4](a, b);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	void	(*tab[5])(int, int);

	tab[0] = ft_addition;
	tab[1] = ft_substraction;
	tab[2] = ft_division;
	tab[3] = ft_multiplication;
	tab[4] = ft_modulo;
	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1)
	{
		write (1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	ft_ft(tab, argv[2][0], a, b);
}
