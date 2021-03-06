/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:22:02 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 20:57:42 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int num, int power)
{
	int n;
	int	i;

	if (power < 0)
		return (0);
	i = 0;
	n = 1;
	while (i < power)
	{
		n = n * num;
		i++;
	}
	return (n);
}
