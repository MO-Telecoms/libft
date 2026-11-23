/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:15:30 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:50:31 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_list(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	while (lst != NULL)
	{
		next = lst->next;
		del(lst->content);
		free(lst);
		lst = next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = NULL;
	tail = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		node = malloc(sizeof(t_list));
		if (node == NULL)
		{
			del(content);
			free_list(head, del);
			return (NULL);
		}
		node->content = content;
		node->next = NULL;
		if (head == NULL)
			head = node;
		else
			tail->next = node;
		tail = node;
		lst = lst->next;
	}
	return (head);
}
