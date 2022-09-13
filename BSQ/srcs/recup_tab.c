/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:29:41 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/26 23:12:45 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/* On compte le nombre de caracteres dans le fichier */
int	count_size(char *argvn)
{
	char	buf[2];
	int		ret;
	int		fd;
	int		i;

	fd = open(argvn, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buf, 1);
	i = 0;
	while (ret != 0)
	{
		ret = read(fd, buf, 1);
		i++;
	}
	if (close(fd) == -1)
		return (-1);
	return (i);
}

/* On copie tous ces caracteres dans un tableau alloue dynamiquement */
char	*gen_string(char *argvn)
{
	char	buf[2];
	int		ret;
	int		fd;
	int		count;
	char	*string;

	count = count_size(argvn);
	if (count == -1)
		return (0);
	string = malloc(sizeof(char) * (count + 1));
	fd = open(argvn, O_RDONLY);
	if (fd == -1 || string == NULL)
		return (0);
	ret = read(fd, buf, 1);
	count = 0;
	while (ret != 0)
	{
		string[count++] = buf[0];
		ret = read(fd, buf, 1);
	}
	string[count] = '\0';
	if (close(fd) == -1)
		return (0);
	return (string);
}

/* On supprime la premiere ligne qui contient des
 * informations dont nous n'avons plus besoin */
void	only_map(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = str[i];
}
