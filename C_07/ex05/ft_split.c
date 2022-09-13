/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:35:11 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/20 13:05:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_size(char *str, char *charset, int count, int len_str)
{
	int	sep;
	int	i;
	int	j;

	sep = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j] || i == len_str - 1)
			{
				if (sep == 0 && i != 0)
					count++;
				sep = 1;
				break ;
			}
			else if (j == ft_strlen(charset) - 1)
				sep = 0;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_strdup(char *str, char *charset, char *dest)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j] || ft_strlen(charset) == 0)
		{
			if (str[i] == charset[j])
				return (i);
			if (j == ft_strlen(charset) - 1 || ft_strlen(charset) == 0)
				dest[i] = str[i];
			if (ft_strlen(charset) == 0)
				break ;
		}
	}
	return (i);
}

void	ft_splitstr(char *str, char *charset, char **tab, int str_len)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
				break ;
			else if (j == ft_strlen(charset) - 1)
			{
				tab[k] = malloc(sizeof(char) * str_len + 1);
				i = i + ft_strdup(&str[i], charset, tab[k]);
				k++;
			}
		}
	}
	tab[k] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		count;

	if (str == NULL || charset == NULL)
		return (0);
	count = 1;
	count = ft_count_size(str, charset, count, ft_strlen(str));
	if (ft_strlen(charset) > 0)
		tab = malloc(sizeof(char *) * count);
	else
	{
		tab = malloc(sizeof(char *) * 2);
		tab[0] = malloc(sizeof(char) * (ft_strlen(str) + 1));
		ft_strdup(str, charset, tab[0]);
		if (ft_strlen(str) == 0)
			tab[0] = 0;
		else
			tab[1] = 0;
		return (tab);
	}
	if (tab == NULL)
		return (0);
	ft_splitstr(str, charset, tab, ft_strlen(str));
	return (tab);
}
