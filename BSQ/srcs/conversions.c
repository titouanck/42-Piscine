/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:22:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/27 12:15:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**convert_from(char **tab, char *symb, int x, int y)
{
	int	i;
	int	j;
	int	**inttab;
	int	p;

	inttab = malloc(sizeof(int) * x * y);
	p = -1;
	while (++p < y)
		inttab[p] = malloc(sizeof(int) * x);
	if (inttab == NULL)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == symb[0])
				inttab[i][j] = 1;
			else if (tab[i][j] == symb[1])
				inttab[i][j] = 0;
			j++;
		}
	}
	return (inttab);
}
