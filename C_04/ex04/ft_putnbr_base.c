/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:49:32 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/17 19:23:52 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if ((base[i] == base[j] && i != j)
				|| base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_print_base(long int nbr, char *base, int base_size)
{
	if (nbr / base_size != 0)
	{
		ft_print_base(nbr / base_size, base, base_size);
		ft_print_base(nbr % base_size, base, base_size);
	}
	else
	{
		write(1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			base_size;

	nb = nbr;
	if (!ft_base_check(base))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	base_size = ft_strlen(base);
	ft_print_base(nb, base, base_size);
}
