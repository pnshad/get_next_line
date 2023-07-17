/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnourish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:57:58 by pnourish          #+#    #+#             */
/*   Updated: 2023/07/07 21:58:01 by pnourish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_line_section_from(int fd, char *section);
char	*ft_strchr_np(char *s, int c);
char	*ft_create_append_to(char *section, char *buffer);
size_t	ft_strlen(const char *str);
char	*ft_extract_line_from(char *section);
char	*ft_remove_line_from(char *section);

#endif
