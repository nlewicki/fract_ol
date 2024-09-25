/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:47:28 by nlewicki          #+#    #+#             */
/*   Updated: 2024/09/25 10:45:50 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (pf_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		pf_putchar_fd('-', fd);
		count++;
		n = -n;
	}
	if (n > 9)
		count += pf_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	pf_putchar_fd(c, fd);
	count++;
	return (count);
}
