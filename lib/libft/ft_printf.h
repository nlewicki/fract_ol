/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:17:34 by nlewicki          #+#    #+#             */
/*   Updated: 2024/09/25 10:44:17 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>

int		pf_putchar_fd(char c, int fd);
int		pf_putstr_fd(char *s, int fd);
int		pf_putnbr_fd(int n, int fd);
int		pf_putnbr_base(unsigned long long n, char *base);
int		ft_printf(const char *format, ...);
int		get_error_printf(int status, int intial);

#endif
