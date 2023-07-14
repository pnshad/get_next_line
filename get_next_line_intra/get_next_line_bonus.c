/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnourish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:56:21 by pnourish          #+#    #+#             */
/*   Updated: 2023/07/07 21:56:25 by pnourish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_remove_last_line(char *section)
{
	int		i;
	int		j;
	char	*cleaned_section;

	if (!section)
		return (NULL);
	i = 0;
	while (section[i] && section[i] != '\n')
		i++;
	if (!section[i])
	{
		free(section);
		return (NULL);
	}
	cleaned_section = (char *)malloc(ft_strlen(section) - i + 1);
	if (!cleaned_section)
		return (NULL);
	i++;
	j = 0;
	while (section[i])
		cleaned_section[j++] = section[i++];
	cleaned_section[j] = '\0';
	free(section);
	return (cleaned_section);
}

char	*ft_line_from_section(char *section)
{
	int		i;
	char	*line;

	if (!section || !*section)
		return (NULL);
	i = 0;
	while (section[i] && section[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	if (section[i] != '\0')
		line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = section[i];
		i--;
	}
	return (line);
}

char	*ft_strjoin_gnl(char *section, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_section;

	if (!section)
	{
		section = (char *)malloc(sizeof(char));
		section[0] = '\0';
	}
	if (!section || !buffer)
		return (NULL);
	new_section = malloc((ft_strlen(section) + ft_strlen(buffer) + 1));
	if (!new_section)
		return (NULL);
	i = -1;
	j = 0;
	while (section[++i])
		new_section[i] = section[i];
	while (buffer[j])
		new_section[i++] = buffer[j++];
	new_section[ft_strlen(section) + ft_strlen(buffer)] = '\0';
	free(section);
	return (new_section);
}

char	*ft_read_section(int fd, char *section)
{
	char	*buffer;
	int		bytes_read;

	if (BUFFER_SIZE == 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr_np(section, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		section = ft_strjoin_gnl(section, buffer);
	}
	free(buffer);
	return (section);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*section[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	section[fd] = ft_read_section(fd, section[fd]);
	if (!section[fd])
		return (NULL);
	line = ft_line_from_section(section[fd]);
	section[fd] = ft_remove_last_line(section[fd]);
	return (line);
}
