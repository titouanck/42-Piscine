/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print_comb2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:59:54 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/07 13:08:02 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	choice_by_situation(char c)
{
	if (c < 10)
	{
		ft_putchar('0');
		ft_putchar(c + 48);
	}
	else
	{
		ft_putchar(c / 10 + 48);
		ft_putchar(c % 10 + 48);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			if (b > 1)
				write(1, ", ", 2);
			choice_by_situation(a);
			ft_putchar(' ');
			choice_by_situation(b);
			b = b + 1;
		}
		a = a + 1;
	}
}
