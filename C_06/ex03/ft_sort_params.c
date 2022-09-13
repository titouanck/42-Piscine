/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:42:25 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/14 20:09:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int			i;
	char		new_l;

	new_l = '\n';
	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, &new_l, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			r = s1[i] - s2[i];
			break ;
		}
	}
	if (r == 0)
		r = s1[i] - s2[i];
	if (r == 0)
		return (0);
	else if (r > 0)
		return (1);
	else
		return (-1);
}

void	ft_print_params(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i <= argc)
		ft_putstr(argv[i]);
}

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	j = 1;
	tmp = 0;
	argc--;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) >= 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_print_params(argc, argv);
}
