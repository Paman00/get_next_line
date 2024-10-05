/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:18:48 by migugar2          #+#    #+#             */
/*   Updated: 2024/10/05 11:41:55 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>

size_t	str_len(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*str_chr(const char *s, int c)
{
	unsigned char	*p;

	if (s == NULL)
		return (NULL);
	p = (unsigned char *)s;
	while (*p)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)p);
	return (NULL);
}

char	*str_dup(const char *s)
{
	char	*s_dup;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = str_len(s);
	s_dup = (char *)malloc(sizeof(char) * (len + 1));
	if (s_dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_dup[i] = (char)s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

char	*str_join(char const *s1, char const *s2)
{
	char	*r;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (str_dup(""));
	s1_len = str_len(s1);
	s2_len = str_len(s2);
	r = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (r == NULL)
		return (r);
	i = 0;
	while (i < s1_len || i < s2_len)
	{
		if (i < s1_len)
			r[i] = s1[i];
		if (i < s2_len)
			r[s1_len + i] = s2[i];
		i++;
	}
	r[s1_len + s2_len] = '\0';
	return (r);
}

char	*free_str(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
