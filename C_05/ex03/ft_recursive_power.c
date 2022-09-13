/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:00:45 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/16 18:21:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	nb_const;

	nb_const = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power - 1 > 0)
		nb = nb * ft_recursive_power(nb_const, power - 1);
	return (nb);
}
