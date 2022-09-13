/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:52:51 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/12 20:37:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len_to_find;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return (str);
	while (i < ft_strlen(str))
	{
		while (str[i] != '\0' && str[i] != to_find[0])
			i++;
		j = 0;
		while (j < len_to_find)
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (j == len_to_find)
			return (&str[i]);
		i++;
	}
	return (0);
}
