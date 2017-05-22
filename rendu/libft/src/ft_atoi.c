/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:44:50 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 21:26:08 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str && !res && !sign && (*str == '+' || *str == '-'))
		sign = (*str++ == '+') ? 1 : -1;
	while (*str && (*str >= '0' && *str <= '9'))
		res = res * 10 + *str++ - '0';
	res *= sign ? sign : 1;
	return (res);
}
