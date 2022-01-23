/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:58:13 by tisoya            #+#    #+#             */
/*   Updated: 2021/10/21 03:58:13 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !del || !(*lst))
		return ;
	while (tmp)
	{
		nxt = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = nxt;
	}
	*lst = NULL;
}
