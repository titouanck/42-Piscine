/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:13:29 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/19 11:54:17 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long int	diff;
	long int	i;

	diff = max - min;
	if (diff < 1)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (diff));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < diff)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (diff);
}
