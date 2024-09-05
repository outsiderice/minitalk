/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:15:00 by amagnell          #+#    #+#             */
/*   Updated: 2024/09/05 10:43:58 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	received(int	signal)
{
	if (signal == SIGUSR1)
		printf("Server received message!\n");
}

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
	struct	sigaction	sa;
	pid_t	pid;

	if (argc != 3)
		return (write(1, "pass two arguments\n", 19));
	sa.sa_handler = received;
	sa.sa_flags = 0;
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (write(1, "wrong pid\n", 10));
	send_int(ft_strlen(argv[2]), pid);
	send_string(argv[2], pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (write(2, "sigaction error\n"));
	usleep(100);
	return (0);
}
