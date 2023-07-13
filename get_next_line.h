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

size_t	ft_strlen_np(const char *str);
char	*ft_strchr_np(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_str_to_line(char *str);
char	*ft_remove_line_str(char *str);
char	*ft_file_to_str(int fd, char *str);
char	*get_next_line(int fd);

#endif
