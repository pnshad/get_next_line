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

size_t	ft_strlen_np(const char *str);
char	*ft_strchr_np(char *s, int c);
char	*ft_strjoin_gnl(char *sx_str, char *buff);
char	*ft_str_to_line(char *str);
char	*ft_remove_line_str(char *str);
char	*ft_file_to_str(int fd, char *str);
char	*get_next_line(int fd);

#endif
