/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:21:32 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/26 23:34:21 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// ft_basics.c
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_printnbr(int nb);
void	ft_putnbr(int nb);

// ft_atoi.c
int		ft_atoi(char *str);

// ft_split.c
char	**ft_split(char *str, int y, int x);

// recup_tab.c
int		count_size(char *argvn);
char	*gen_string(char *argvn);
void	only_map(char *str);

// algorithm.c
int		ft_min(int a, int b, int c);
int		ft_find_max_tab(int **tab, int *x, int *y);
void	ft_mapping(int **tab, int x, int y);
char	**ft_call_bsq(char **tab, int y, int x, char *symb);

// check_file.c
int		gen_file(void);
int		ft_ck_first(char *str, char *symb, int *y);
int		ft_ck_lines(char *str, int y, int *x);
int		ft_ck_symb(char *str, char *symb);
int		ft_check_file(char *str, char *symb, int *y, int *x);

// conversions.c
int		**convert_from(char **tab, char *symb, int x, int y);

#endif
