/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:00:57 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/07 17:35:09 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	digit_counter(int *tmp)
{
	int	digits;

	digits = 1;
	while (*tmp / 10 > 0)
	{
		digits = digits + 1;
		*tmp = *tmp / 10;
	}
	return (digits);
}

int	check_negative(int *nb)
{
	if (*nb < 0)
	{
		if (*nb == -32768)
		{
			ft_putchar('-');
			ft_putchar('3');
			ft_putchar('2');
			ft_putchar('7');
			ft_putchar('6');
			ft_putchar('8');
			return (1);
		}
		else
		{
			*nb = *nb * -1;
			ft_putchar('-');
			return (0);
		}
	}
}

void	display_digit_by_digit(int *c, int *d, int *t, int *n)
{
	int	len;

	len = *d;
	while (*c < *d)
	{
		*t = *n;
		while (*d > 1 + *c)
		{
			*t = *t / 10;
			*d = *d - 1;
		}
		*t = *t % 10;
		*c = *c + 1;
		*d = len;
		ft_putchar(*t + 48);
	}
}

void	ft_putnbr(int nb)
{	
	int	digits;
	int	tmp;
	int	current_digit;

	if (check_negative(&nb) == 1)
		return ;
	tmp = nb;
	current_digit = 0;
	digits = digit_counter(&tmp);
	tmp = nb;
	display_digit_by_digit(&current_digit, &digits, &tmp, &nb);
}
