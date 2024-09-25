/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:47:04 by nlewicki          #+#    #+#             */
/*   Updated: 2024/09/25 10:44:38 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar_fd(char c, int fd)
{
	if (get_error_printf (0, 0) == 0)
		get_error_printf (write(fd, &c, 1), 0);
	return (1);
}
