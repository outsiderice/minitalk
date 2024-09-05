/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:34:39 by amagnell          #+#    #+#             */
/*   Updated: 2024/09/05 09:07:59 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(int count, unsigned long long nbr, char *base, const char *type)
{
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		count = ft_putnbr(count, nbr / ft_strlen(base), base, type);
		if (count == -1)
			return (-1);
		count = ft_putnbr(count, nbr % ft_strlen(base), base, type);
	}
	else if (nbr < (unsigned long)ft_strlen(base))
		count = count + ft_putchar(base[nbr]);
	return (count);
}
