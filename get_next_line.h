/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:56:01 by stemsama          #+#    #+#             */
/*   Updated: 2022/11/18 15:56:01 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_rest(char *storage);
char	*get_line(char *storage);
char	*read_file(int fd, char *storage);

char	*get_next_line(int fd);

int		ft_strchr_g(char *s, int c);
size_t	ft_strlen_g(char *str);
char	*ft_strjoin_g(char *storage, char *buffer);

#endif