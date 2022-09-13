/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:06:48 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/17 15:34:40 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_whitespace_and_signs(char *str, int *i)
{
	int	neg;

	neg = 0;
	while (str[*i] == 32 || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			neg++;
		(*i)++;
	}
	return (neg);
}

int	ft_check_base(char *base)
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
				|| base[j] == '-' || base[j] == '+'
				|| base[j] == ' ' || (base[j] >= '\t' && '\r' >= base[j]))
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_convert_base(char c, char *base, long int *nbr)
{
	int	pos_in_base;
	int	len;

	pos_in_base = -1;
	len = 0;
	while (base[len])
	{
		if (c == base[len])
			pos_in_base = len;
		len++;
	}
	if (pos_in_base == -1)
		return (0);
	*nbr = *nbr * len + pos_in_base;
	return (len);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	nbr;
	int			neg;
	int			i;

	nbr = 0;
	i = 0;
	neg = ft_whitespace_and_signs(str, &i);
	if (!ft_check_base(base))
		return (0);
	while (ft_convert_base(str[i], base, &nbr))
		i++;
	if (neg % 2 != 0)
		nbr = nbr * (-1);
	return (nbr);
}
