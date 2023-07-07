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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *sx_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!sx_str)
	{
		sx_str = (char *)malloc(1 * sizeof(char));
		sx_str[0] = '\0';
	}
	if (!sx_str || !buff)
		return (NULL);
	str = malloc((ft_strlen(sx_str) + ft_strlen(buff) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (sx_str)
		while (sx_str[++i] != '\0')
			str[i] = sx_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(sx_str) + ft_strlen(buff)] = '\0';
	free(sx_str);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*tab;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i ++;
	tab = (char *)malloc(sizeof(char) * (i + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tab[i] = str[i];
		i ++;
	}
	if (str[i] == '\n')
	{
		tab[i] = str[i];
		i ++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_next_string(char *str)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (str[i] && str[i] != '\n')
		i ++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tab)
		return (NULL);
	i ++;
	j = 0;
	while (str[i])
		tab[j++] = str[i++];
	tab[j] = '\0';
	free(str);
	return (tab);
}
