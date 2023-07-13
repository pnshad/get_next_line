/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnourish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:55:40 by pnourish          #+#    #+#             */
/*   Updated: 2023/07/07 21:55:52 by pnourish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remove_line_str(char *str)
{
	int		i;
	int		j;
	char	*str_out;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str_out = (char *)malloc(ft_strlen_np(str) - i + 1);
	if (!str_out)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		str_out[j++] = str[i++];
	str_out[j] = '\0';
	free(str);
	return (str_out);
}

char	*ft_str_to_line(char *str)
{
	int		i;
	char	*line;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	if (str[i] != '\0')
		line[i+1] = '\0';
	while (i >= 0)
	{
		line[i] = str[i];
		i--;
	}
	return (line);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str_out;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str_out = malloc((ft_strlen_np(s1) + ft_strlen_np(s2) + 1));
	if (!str_out)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str_out[i] = s1[i];
	while (s2[j])
		str_out[i++] = s2[j++];
	str_out[ft_strlen_np(s1) + ft_strlen_np(s2)] = '\0';
	free(s1);
	return (str_out);
}

char	*ft_file_to_str(int fd, char *str)
{
	char	*buf;
	int		bytes_read;

	if (BUFFER_SIZE == 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_np(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_file_to_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_str_to_line(str);
	str = ft_remove_line_str(str);
	return (line);
}
