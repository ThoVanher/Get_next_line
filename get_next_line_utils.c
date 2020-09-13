/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvanher <thvanher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:50:01 by thvanher          #+#    #+#             */
/*   Updated: 2020/08/11 10:50:22 by thvanher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	b;
	int				i;
	int				len;

	str = (char *)s;
	b = (unsigned char)c;
	i = -1;
	len = ft_strlen(str);
	while (++i < len + 1)
	{
		if (str[i] == b)
			return (str + i);
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	i = 0;
	if (!(dest = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;
	size_t				i;

	csrc = (const unsigned char *)src;
	cdst = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (cdst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	new = 0;
	if (!s1 && !s2)
		return (new);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup((char *)s2) : ft_strdup((char *)s1));
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(new = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (0);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}
