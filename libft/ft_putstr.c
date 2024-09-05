/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:25 by amagnell          #+#    #+#             */
/*   Updated: 2024/09/05 10:25:05 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[j] != '\0')
	{
		count = count + ft_putchar(str[j]);
		if (count == -1)
			return (-1);
		j++;
	}
	return (count);
}
