/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:47:28 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/23 21:47:51 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	ft_addition(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_substraction(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_division(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	ft_putnbr(a / b);
}

void	ft_multiplication(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_modulo(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	ft_putnbr(a % b);
}
