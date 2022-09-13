/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:34:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/23 21:53:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

// ft_putnbr.c
void	ft_putnbr(int nb);
void	ft_printnbr(int nb);
void	ft_putchar(char c);

// ft_operations.c
void	ft_addition(int a, int b);
void	ft_substraction(int a, int b);
void	ft_division(int a, int b);
void	ft_multiplication(int a, int b);
void	ft_modulo(int a, int b);

// ft_atoi.c
void	whitespace_and_signs(char *str, int *i, int *minus);
int		ft_atoi(char *str);

#endif
