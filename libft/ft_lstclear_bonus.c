/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:33:52 by amagnell          #+#    #+#             */
/*   Updated: 2023/09/25 19:05:50 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*node;
	t_list	*to_delete;

	node = *lst;
	while (node != NULL)
	{
		to_delete = node;
		node = node->next;
		del(to_delete->content);
		free(to_delete);
	}
	*lst = NULL;
}
