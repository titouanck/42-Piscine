/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:25:16 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/12 10:18:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				r;

	i = 0;
	r = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			r = s1[i] - s2[i];
			break ;
		}
	}
	if (r == 0 && i < n)
		r = s1[i] - s2[i];
	if (r == 0)
		return (0);
	else if (r > 0)
		return (1);
	else
		return (-1);
}
