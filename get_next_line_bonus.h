/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:41:47 by migugar2          #+#    #+#             */
/*   Updated: 2024/10/05 18:48:52 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stddef.h>

size_t	str_len(const char *s);
char	*str_chr(const char *s, int c);
char	*str_dup(const char *s);
char	*str_join(char const *s1, char const *s2);
char	*free_str(char **str);

char	*get_next_line(int fd);

#endif
