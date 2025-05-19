/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:05:56 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/16 12:14:47 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*last;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		last = current->next;
		del(current->content);
		free(current);
		current = last;
	}
	*lst = 0;
}
