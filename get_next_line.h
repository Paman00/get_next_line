/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:19:01 by migugar2          #+#    #+#             */
/*   Updated: 2024/10/05 16:09:14 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

size_t	str_len(const char *s);
char	*str_chr(const char *s, int c);
char	*str_dup(const char *s);
char	*str_join(char const *s1, char const *s2);
char	*free_str(char **str);

char	*get_next_line(int fd);

#endif
