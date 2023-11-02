/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:34 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/28 19:55:48 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"

int		get_len(int signum, int pos, int num);
void	get_string(int signum, unsigned char *str, int len);
void	end_transmission(unsigned char *str, int *bit_count, int *len);

#endif
