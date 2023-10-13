/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:15:00 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/13 16:00:40 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (write(1, "pass two arguments", 18));
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (write(1, "wrong pid", 9));
	//turn string to binary
	//then send it to server
	//one sigusr is for 1s and the other for 0s
	//signal in some way ?? that the string has finished
}
