/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:22:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/24 19:15:01 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void sig_handler(int signum);

static void	sig_handler(int signum)
{
	static int				bit_count = -1;
	static int				len = 0;
	static int				client_pid = 0;
	static unsigned char	*str = NULL;
	
	ft_printf("1\n");
	if (++bit_count < 32)
		len = get_int(signum, bit_count, len);
	ft_printf("2\n");
	if (bit_count == 31)
		str = ft_calloc(len + 1, sizeof(char));
	ft_printf("3\n");
	if (bit_count > 32 && bit_count < 64)
		client_pid = get_int(signum, bit_count, client_pid);
	ft_printf("4\n");
	if (bit_count >= 64)
		get_string(signum, str, bit_count);
	ft_printf("5\n");
	if (bit_count == 63 + len * 8)
		end_transmission((char *)str, &bit_count, &len, &client_pid);
}

int	get_int(int signum, int bit_pos, int num)
{
	if (signum == SIGUSR1)
		num = (num | (1 << (31 - bit_pos)));
	return (num);
}

void get_string(int signum, unsigned char *str, int bit_count)
{
	static int		bits = 0;
	static char		c = 0;

	if (signum == SIGUSR1)
		c = c | 1 << bits;
	bits++;
	if (bit_count % 8 == 0)
	{
		str[bit_count / 8 - 1] = c;
		c = 0;
		bits = 0;
	}
}

void end_transmission(char *str, int *bit_count, int *len, int *client_pid)
{
	ft_printf("%s", str);
	if(str != NULL)
	{
		free(str);
		str = NULL;
	}
	*bit_count = -1;
	*len = 0;
	*client_pid = 0;
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	ft_printf("SERVER PID:%i\n", getpid());
	while(1)
	{
		usleep(100);
	}
	return (0);
}
