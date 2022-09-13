/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:45:55 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/20 22:46:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_str;
	int			i;

	s_str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_str == NULL)
		return (0);
	i = 0;
	s_str[ac].str = 0;
	while (i < ac)
	{
		s_str[i].size = ft_strlen(av[i]);
		s_str[i].str = av[i];
		s_str[i].copy = ft_strdup(av[i]);
		i++;
	}
	return (s_str);
}
