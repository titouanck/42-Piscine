/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:38:45 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/16 12:10:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	p;

	p = 1;
	while (p * p < nb)
		p++;
	if (p * p == nb)
		return (p);
	else
		return (p - 1);
}

int	ft_digits(int nb)
{
	int	digits;
	int	nb_const;
	int	i;

	digits = 1;
	nb_const = nb;
	while (nb / 10 != 0)
	{
		digits++;
		nb = nb / 10;
	}
	i = 0;
	nb = 0;
	while (i < digits)
	{
		nb = nb + nb_const % 10;
		nb_const = nb_const / 10;
		i++;
	}
	if (nb % 3 == 0 || nb % 9 == 0)
		return (0);
	return (digits);
}

int	ft_is_prime(int nb)
{
	int	nb_sqrt;
	int	x;

	nb_sqrt = ft_sqrt(nb);
	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	if (nb % 2 == 0 || nb % 10 == 5 || nb % 10 == 0 || nb <= 1)
		return (0);
	else if (ft_digits(nb) == 0)
		return (0);
	x = 2;
	while (x <= nb_sqrt)
	{
		if (nb % x == 0)
			return (0);
		x = x + 1;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}
