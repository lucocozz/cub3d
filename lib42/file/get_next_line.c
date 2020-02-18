/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:04:19 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/07 20:30:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static char		*ft_getline(char **buffer, int size, int *ret)
{
	int		i;
	char	*tmp;
	char	*line;

	tmp = *buffer;
	i = ft_strclen(tmp, '\n');
	*ret = (i == -1 ? 0 : 1);
	i = (i == -1 ? size : i);
	line = ft_substr(tmp, 0, i);
	if (i + 1 < size)
		*buffer = ft_substr(tmp, i + 1, size);
	else
		*buffer = NULL;
	free(tmp);
	return (line);
}

static int		ft_getbuff(char **buffer, int fd)
{
	int		chr;
	int		size;
	char	tmp_read[BUFFER_SIZE + 1];

	while (1)
	{
		ft_bzero(tmp_read, BUFFER_SIZE + 1);
		if ((size = read(fd, tmp_read, BUFFER_SIZE)) == -1)
			return (-1);
		else if (size == 0)
			break ;
		*buffer = ft_strjoin_free(*buffer, tmp_read);
		chr = ft_strclen(tmp_read, '\n');
		if (chr > -1 || (chr == -1 && size < BUFFER_SIZE))
			break ;
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	int			ret;
	static char	*buffer;
	char		tmp[BUFFER_SIZE + 1];

	ft_bzero(tmp, BUFFER_SIZE + 1);
	if (!buffer)
	{
		if ((ret = read(fd, tmp, BUFFER_SIZE)) <= 0)
		{
			*line = ft_strdup("");
			return (ret);
		}
		buffer = ft_strdup(tmp);
	}
	if ((i = ft_strclen(buffer, '\n')) == -1 &&
	(ret = ft_getbuff(&buffer, fd)) == -1)
	{
		ft_memdel((void**)&buffer);
		return (-1);
	}
	*line = ft_getline(&buffer, ft_strlen(buffer), &ret);
	return (ret);
}
