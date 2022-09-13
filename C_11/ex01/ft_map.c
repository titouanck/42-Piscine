/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:15:04 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/23 20:28:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*f_tab;

	i = 0;
	f_tab = malloc(sizeof(int) * length);
	while (i < length)
	{
		f_tab[i] = f(tab[i]);
		i++;
	}
	return (f_tab);
}
