/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:17:51 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/16 13:00:49 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int			i;
	int			src_len;
	char		*r;

	src_len = ft_strlen(src);
	r = malloc((src_len + 1) * sizeof(char));
	if (r == NULL)
		return (0);
	i = 0;
	while (i < src_len)
	{
		r[i] = src[i];
		i++;
	}
	r[i] = src[i];
	return (r);
}
