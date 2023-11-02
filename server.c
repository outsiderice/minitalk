/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:22:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/11/01 16:02:54 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum);

static void	sig_handler(int signum)
{
	static int				bit_count = -1;
	static int				len = 0;
	static unsigned char	*str = NULL;
	static int				check = 0;

	bit_count++;
	if (bit_count <= 31 && check == 0)
	{
		len = get_len(signum, bit_count, len);
		if (bit_count == 31)
			str = ft_calloc(len + 1, sizeof(char));
	}
	if (bit_count > 31)
	{
		get_string(signum, str, len);
		if (bit_count == 31 + len * 8)
		{
			end_transmission(str, &bit_count, &len);
			free(str);
			if (str != NULL)
				str = NULL;
		}
	}
}

void	end_transmission(unsigned char *str, int *bit_count, int *len)
{
	ft_printf("%s\n", str);
	*bit_count = -1;
	*len = 0;
}

int	get_len(int signum, int pos, int len)
{
	if (signum == SIGUSR1)
		len = (len | (2147483648 >> pos));
	return (len);
}

void	get_string(int signum, unsigned char *str, int len)
{
	static int					bits = 0;
	static unsigned char		byte = 0;
	static int					i = 0;

	if (signum == SIGUSR1)
		byte = (byte >> 1) | 128;
	else
		byte = (byte >> 1);
	bits++;
	if (bits == 8)
	{
		str[i] = byte;
		byte = 0;
		bits = 0;
		i++;
	}
	if (i == len)
	{
		str[i] = '\0';
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	ft_printf("SERVER PID:%i\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
