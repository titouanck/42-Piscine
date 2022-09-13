/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:51:27 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/09 13:52:11 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	letter;
	int	i;

	letter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		letter++;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (letter == 1)
				str[i] = str[i] - 'a' + 'A';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (letter > 1)
				str[i] = str[i] - 'A' + 'a';
		}
		else if (str[i] < '0' || str[i] > '9')
			letter = 0;
		i++;
	}
	return (str);
}
