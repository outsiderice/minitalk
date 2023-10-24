/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:34 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/23 22:44:40 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"

int     get_int(int signum, int bit_pos, int num);
void     get_string(int signum, unsigned char *str, int bit_count);
void    end_transmission(char *str, int *bit_count, int *len, int *client_pid);

#endif
