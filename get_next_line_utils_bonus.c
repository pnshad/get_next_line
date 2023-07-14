/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnourish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:56:52 by pnourish          #+#    #+#             */
/*   Updated: 2023/07/07 21:56:56 by pnourish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_np(const char *s)
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
