/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:22:29 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/14 09:56:40 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_negative(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		return (nb * -1);
	}
	return (nb);
}

int	puissance(int nb, int puis)
{
	int	i;
	int	number;

	i = 0;
	number = nb;
	while (i < puis - 1)
	{
		nb = nb * number;
		i++;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int	nb_const;
	int	digits;

	digits = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	nb_const = is_negative(nb);
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		digits++;
	}
	while (digits - 1 > 0)
	{
		ft_putchar('0' + nb_const / puissance(10, digits - 1) % 10);
		digits--;
	}
	ft_putchar('0' + nb_const % 10);
}
