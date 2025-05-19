/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:38:56 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/16 12:19:20 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nouvel_list;

	nouvel_list = (t_list *)malloc(sizeof(t_list));
	if (!nouvel_list)
		return (0);
	nouvel_list->content = content;
	nouvel_list->next = 0;
	return (nouvel_list);
}
