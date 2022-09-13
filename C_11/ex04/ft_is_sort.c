/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:52:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/23 21:17:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	tri1;
	int	tri2;

	tri1 = 0;
	tri2 = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			tri1++;
		if (f(tab[i], tab[i + 1]) < 0)
			tri2++;
		i++;
	}
	if (tri1 == 0 || tri2 == 0)
		return (1);
	return (0);
}
