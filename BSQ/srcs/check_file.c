/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:22:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/27 11:03:37 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	gen_file(void)
{
	int		fd;
	char	ch;

	fd = open(".user_input", O_WRONLY | O_TRUNC);
	if (fd == -1)
		fd = open(".user_input", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (0);
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		write(fd, &ch, 1);
	}
	if (close (fd) == -1)
		return (0);
	return (1);
}

int	ft_ck_first(char *str, char *symb, int *y)
{
	int	index;
	int	i;

	index = 0;
	while (str[index] && str[index] > 31)
		index++;
	if (index < 4 || str[index] != '\n')
		return (0);
	symb[3] = '\0';
	symb[2] = str[index - 1];
	symb[1] = str[index - 2];
	symb[0] = str[index - 3];
	if (symb[0] == symb[1] || symb[1] == symb[2] || symb[2] == symb[3])
		return (0);
	i = 0;
	while (i < (index - 3))
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		*y = *y * 10 + str[i++] - 48;
	}
	return (index);
}

int	ft_ck_lines(char *str, int y, int *x)
{
	int	i;
	int	count;
	int	bl;

	i = 0;
	bl = 0;
	while (str[i] && str[i] > 31)
		i++;
	count = 0;
	while (str[i] && str[++i] != '\n')
			(*x)++;
	while (str[i++])
		if (str[i] != '\n')
			count++;
	else if ((*x) == count)
		count = 0;
	else
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			bl++;
	if (bl - 1 != y || bl < 2)
		return (0);
	return (1);
}

int	ft_ck_symb(char *str, char *symb)
{
	int	i;

	i = 0;
	while (str[i] && str[i] > 31)
		i++;
	while (str[++i])
	{
		if (!(str[i] == symb[0] || str[i] == symb[1] || str[i] == '\n'))
			return (0);
	}
	return (1);
}

int	ft_check_file(char *str, char *symb, int *y, int *x)
{
	if (ft_ck_first(str, symb, y) == 0
		|| ft_ck_lines(str, *y, x) == 0
		|| ft_ck_symb(str, symb) == 0)
		return (0);
	return (1);
}
