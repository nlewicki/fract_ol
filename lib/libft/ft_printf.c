/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:08:59 by nlewicki          #+#    #+#             */
/*   Updated: 2024/09/25 10:47:50 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier(const char c, va_list arg)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(arg, char *);
		if (str == NULL)
			return (pf_putstr_fd("(null)", 1));
		else
			return (pf_putstr_fd(str, 1));
	}
	else if (c == 'd')
		return (pf_putnbr_fd(va_arg(arg, int), 1));
	else if (c == 'c')
		return (pf_putchar_fd(va_arg(arg, int), 1));
	else if (c == 'i')
		return (pf_putnbr_fd(va_arg(arg, int), 1));
	else if (c == 'x')
		return (pf_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (pf_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (c == 'u')
		return (pf_putnbr_base(va_arg(arg, unsigned int), "0123456789"));
	else if (c == '%')
		return (pf_putchar_fd('%', 1));
	return (0);
}

static int	ft_format(const char c, va_list arg)
{
	int		count;
	void	*ptr;
	char	*str;

	str = "0123456789abcdef";
	count = 0;
	if (c == 'p')
	{
		ptr = va_arg(arg, void *);
		if (ptr == NULL)
			return (pf_putstr_fd("0x0", 1));
		else
		{
			pf_putstr_fd("0x", 1);
			return (pf_putnbr_base((unsigned long long)ptr, str) + 2);
		}
	}
	else
		count = ft_specifier(c, arg);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, format);
	i = 0;
	count = 0;
	get_error_printf(0, 1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count += ft_format(format[i], arg);
		}
		else
			count += pf_putchar_fd(format[i], 1);
		if (get_error_printf(0, 0) == -1)
			return (-1);
		i++;
	}
	va_end(arg);
	return (count);
}

// int	main(void)
// {
// 	int	i;

// 	i = 42;
// 	ft_printf("!!!My printf!!!\n");
// 	ft_printf("Hallo Welt %d %d %d\n", i, i ,i);
// 	ft_printf("Hallo Welt %s\n", "Hallo");
// 	ft_printf("Hallo Welt %c\n", 'H');
// 	ft_printf("Hallo Welt %p\n", "16");
// 	ft_printf("Hallo Welt %i\n", i);
// 	ft_printf("Hallo Welt %x\n", 42);
// 	ft_printf("Hallo Welt %X\n", 42);
// 	ft_printf("Hallo Welt %u\n", 42);
// 	ft_printf("Hallo Welt %%\n");
// 	printf("!!!The real printf!!!\n");
// 	printf("Hallo Welt %d\n", i);
// 	printf("Hallo Welt %s\n", "Hallo");
// 	printf("Hallo Welt %c\n", 'H');
// 	printf("Hallo Welt %p\n", "16");
// 	printf("Hallo Welt %i\n", i);
// 	printf("Hallo Welt %x\n", 42);
// 	printf("Hallo Welt %X\n", 42);
// 	printf("Hallo Welt %u\n", 42);
// 	printf("Hallo Welt %%\n");

// 	return (0);
// }
