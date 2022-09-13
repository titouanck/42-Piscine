/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:27:29 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/13 20:27:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	while (i < size - dest_len && i < src_len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	while (i < size - dest_len)
	{
		dest[dest_len + i] = '\0';
		i++;
	}
	if (size >= dest_len)
		return (dest_len + src_len);
	else
		return (size + src_len);
}
