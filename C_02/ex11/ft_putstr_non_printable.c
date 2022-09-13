/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:27 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/11 14:31:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	print_hexadecimal_value(char *hex, unsigned char c)
{
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c - 16 * (c / 16)]);
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[17];
	int		i;

	i = 0;
	ft_strcpy(hex, "0123456789abcdef");
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] >= 32 && (unsigned char)str[i] <= 127)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			print_hexadecimal_value(hex, str[i]);
		}
		i++;
	}
}
