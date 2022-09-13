/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:13:29 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/19 11:29:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*m;
	int	diff;
	int	i;

	diff = max - min;
	if (diff < 1)
		return (NULL);
	m = malloc((diff) * sizeof(int));
	if (m == NULL)
		return (0);
	i = 0;
	while (i < diff)
	{
		m[i] = min + i;
		i++;
	}
	return (m);
}
