/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvanher <thvanher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:50:01 by thvanher          #+#    #+#             */
/*   Updated: 2020/09/14 10:12:57 by thvanher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trunc_s_buff(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (str[++i])
		len++;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str) - i))))
		return (0);
	j = 0;
	if (str[i + 1])
	{
		while (str[i + 1])
			res[j++] = str[i++ + 1];
	}
	res[j] = '\0';
	return (res);
}

int		read_until_n(char **s_buff, int fd, char *buf)
{
	int		ret;
	int		count;
	int		len;
	char	*tmp;

	ret = 1;
	count = 0;
	if ((*s_buff == 0) && !(*s_buff = (char *)malloc(sizeof(char))))
		return (0);
	while (!(ft_strchr(*s_buff, '\n')) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tmp = *s_buff;
		*s_buff = ft_strjoin(*s_buff, buf);
		free(tmp);
	}
	if (!ret)
		len = ft_strlen(*s_buff);
	if (!count && !ret && (*s_buff)[len - 1] != '\n' && (*s_buff)[0] != 0)
		count++;
	if (count == 1 && !ret && (*s_buff)[len - 1] != '\n' && (*s_buff)[0] != 0)
		ret = 1;
	free(buf);
	return (ret);
}

int		get_the_line(char **s_buff, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (((*s_buff)[i]) && (*s_buff)[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (((*s_buff)[i]) && (*s_buff)[i] != '\n')
	{
		(*line)[i] = (*s_buff)[i];
		i++;
	}
	tmp = *s_buff;
	(*line)[i] = '\0';
	*s_buff = trunc_s_buff(*s_buff);
	free(tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*s_buff = 0;
	int			ret;
	char		*buf;

	if (!(buf = (char *)malloc(sizeof(char) + (BUFFER_SIZE + 1))))
		return (-1);
	if (!line || fd < 0 || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	ret = read_until_n(&s_buff, fd, buf);
	if (ret)
	{
		get_the_line(&s_buff, line);
		return (1);
	}
	else
	{
		get_the_line(&s_buff, line);
		return (0);
	}
}
