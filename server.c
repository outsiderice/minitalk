/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:22:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/13 16:00:13 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_printf("%i", getpid());
	//receive signal from client??
	//stay open after client string ends cause other clients may send you more strings
}
