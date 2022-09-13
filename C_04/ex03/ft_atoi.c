/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:41:08 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/12 23:12:08 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespace_and_signs(char *str, int *i, int *minus)
{
	while (str[*i] == 32 || (str[*i] >= '\t' && str[*i] <= '\r'))
	{
		(*i)++;
	}
	while (str[*i] != '\0')
	{
		if (str[*i] == '-')
			(*minus)++;
		else if (str[*i] != '+')
			return ;
		(*i)++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	minus;

	i = 0;
	nbr = 0;
	minus = 0;
	whitespace_and_signs(str, &i, &minus);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (minus % 2 != 0)
		nbr = nbr * -1;
	return (nbr);
}
