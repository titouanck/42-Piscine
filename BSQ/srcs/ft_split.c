/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:41:39 by pbizien           #+#    #+#             */
/*   Updated: 2022/07/26 23:10:58 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, int y, int x)
{
	int		i;
	char	**result;
	int		j;
	int		n;

	i = -1;
	result = malloc(sizeof(char *) * (y + 1));
	while (++i < y)
		result[i] = malloc(sizeof(char) * (x + 1));
	i = -1;
	n = 0;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '\n')
			result[n][j++] = str[i];
		else
		{
			result[n++][j] = '\0';
			j = 0;
		}
	}
	result[n] = 0;
	free(str);
	return (result);
}
