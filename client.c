/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:15:00 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/28 19:40:50 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(char *str, int pid)
{
	int	bit_count;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		bit_count = 0;
		while (bit_count < 8)
		{
			if ((str[i] & (1 << bit_count)) != 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			usleep(100);
			bit_count++;
		}
		i++;
	}
}

void	send_int(unsigned int n, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((n & (2147483648 >> i)) == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (write(1, "pass two arguments\n", 19));
	ft_printf("number of arguments right\n");
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (write(1, "wrong pid\n", 10));
	ft_printf("pid passed correct\n");
	send_int(ft_strlen(argv[2]), pid);
	ft_printf("len sent\n");
	send_string(argv[2], pid);
	ft_printf("string sent\n");
	usleep(100);
	return (0);
}
