/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnourish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:58:29 by pnourish          #+#    #+#             */
/*   Updated: 2023/07/07 21:58:31 by pnourish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

char	*get_next_line(int fd);
char	*ft_read_section(int fd, char *section);
char	*ft_strchr_np(char *s, int c);
char	*ft_strjoin_gnl(char *section, char *buffer);
size_t	ft_strlen(const char *str);
char	*ft_line_from_section(char *section);
char	*ft_remove_last_line(char *section);

#endif
