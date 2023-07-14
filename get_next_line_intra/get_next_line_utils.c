/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnourish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:57:27 by pnourish          #+#    #+#             */
/*   Updated: 2023/07/07 21:57:31 by pnourish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_np(char *s, int c)
{
	if (s)
	{
		while (*s != (char)c && *s)
			s++;
		if (*s == (char)c)
			return (s);
	}
	return (NULL);
}
