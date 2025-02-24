/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:43:09 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/24 12:56:16 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	ft_handle_sign(const char *str, int *sign, int i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

static int	ft_process_integer(const char *str, float *result, int i)
{
	int	has_digits;

	has_digits = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_digits = 1;
		*result = *result * 10.0 + (str[i] - '0');
		i++;
	}
	if (!has_digits)
		return (-1);
	return (i);
}

static int	ft_process_decimal(const char *str, float *result, int i)
{
	float	decimal;
	float	power;

	decimal = 0.0;
	power = 1.0;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		power *= 10.0;
		decimal = decimal * 10.0 + (str[i] - '0');
		i++;
	}
	*result += decimal / power;
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-1);
	return (0);
}

float	ft_atof(const char *str)
{
	int		i;
	int		sign;
	float	result;

	if (!str || !*str)
		return (0.0 / 0.0);
	sign = 1;
	result = 0.0;
	i = ft_skip_whitespace(str);
	i = ft_handle_sign(str, &sign, i);
	i = ft_process_integer(str, &result, i);
	if (i == -1)
		return (0.0 / 0.0);
	if (str[i] == '.')
	{
		if (ft_process_decimal(str, &result, i) == -1)
			return (0.0 / 0.0);
	}
	else if (str[i] != '\0')
		return (0.0 / 0.0);
	return (result * sign);
}
