/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:49:32 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/18 19:14:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_whitespace_and_signs(char *str, int *i);
int		ft_check_base(char *base);
int		ft_convert_base0(char c, char *base, long int *nbr);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_size(long int nb, int base_size, int negative)
{
	int	counter;

	counter = 1;
	if (negative)
		counter++;
	while (nb / base_size != 0)
	{
		nb = nb / base_size;
		counter++;
	}
	return (counter);
}

long int	ft_check_negative(long int *nb)
{
	if (*nb < 0)
	{
		*nb = *nb * (-1);
		return (1);
	}
	return (0);
}

char	*ft_convert_base2(long int nb, char *base)
{
	int		base_size;
	int		count_size;
	int		negative;
	char	*nbr;

	if (!ft_check_base(base))
		return (0);
	negative = ft_check_negative(&nb);
	base_size = ft_strlen(base);
	count_size = ft_count_size(nb, base_size, negative);
	nbr = malloc(sizeof(char) * (count_size + 1));
	nbr[count_size] = '\0';
	while (nb > 0)
	{
		nbr[count_size - 1] = base[nb % base_size];
		nb = nb / base_size;
		count_size--;
	}
	if (negative)
		nbr[0] = '-';
	return (nbr);
}
