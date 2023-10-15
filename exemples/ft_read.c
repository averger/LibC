/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:01:20 by averger           #+#    #+#             */
/*   Updated: 2018/08/22 12:01:46 by averger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char    *ft_convert_list(t_list *list)
{
	char    *str;
	int     i;
	int     len;

	len = ft_list_size(list);
	i = len - 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (i >= 0)
	{
		str[i] = (list->data);
		list = list->next;
		i--;
	}
	str[len] = '\0';
	return (str);
}

char    *mk_conv(void)
{
	char    *str;
	t_list  *list;
	char    b;
	int     is_not_end;

	is_not_end = read(0, &b, 1);
	list = create_list(b);
	while (is_not_end > 0)
	{
		is_not_end = read(0, &b, 1);
		list_push_front(&list, b);
	}
	str = ft_convert_list(list);
	return (str);
}
