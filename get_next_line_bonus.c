/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:04:22 by nali              #+#    #+#             */
/*   Updated: 2021/12/12 09:04:22 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_output_string(char *str, int *bytesread, int *i, char *output)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (str[len])
		len++;
	while (str[j] != '\n' && j < len)
		j++;
	if (str[j] == '\n')
		j++;
	*bytesread = len;
	*i = j;
	output = (char *)malloc((j + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_strlcpy(output, str, j + 1);
	return (output);
}

char	*read_buffer(int fd, int *flag)
{
	char	*buf;
	int		bytesread;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytesread = read(fd, buf, BUFFER_SIZE);
	if (bytesread > 0)
	{
		if (bytesread != BUFFER_SIZE)
			*flag = 1;
		buf[bytesread] = '\0';
		return (buf);
	}
	*flag = 1;
	free(buf);
	return (NULL);
}

char	*read_till_newline(int fd, char *str, int *flg)
{
	char	*buffer;
	int		flag;

	flag = *flg;
	buffer = read_buffer(fd, &flag);
	if (buffer != NULL)
	{
		if (str == NULL)
			str = buffer;
		else
			str = str_concat(str, buffer);
	}
	if (str != NULL)
	{
		while (ft_strchr(str, '\n') == NULL && flag == 0)
		{
			buffer = read_buffer(fd, &flag);
			*flg = flag;
			if (buffer != NULL)
				str = str_concat(str, buffer);
			else
				break ;
		}
	}
	return (str);
}

char	*get_line(int fd, char **remaining, int *flg)
{	
	char		*str;
	int			bytesread;
	int			i;
	char		*output;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = *remaining;
	output = NULL;
	str = read_till_newline(fd, str, flg);
	if (str == NULL)
		return (NULL);
	output = get_output_string(str, &bytesread, &i, output);
	if (bytesread > i)
	{
		*remaining = (char *)malloc((bytesread - i + 1) * sizeof(char));
		if (!remaining)
			return (NULL);
		ft_strlcpy(*remaining, &str[i], bytesread - i + 1);
	}
	else
		*remaining = NULL;
	free(str);
	return (output);
}

char	*get_next_line(int fd)
{
	static t_GNL	*head;
	t_GNL			*tmp;
	char			*str;

	if (head == NULL)
		head = ft_lstnew(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_lstnew(fd);
		tmp = tmp->next;
	}
	str = get_line(tmp->fd, &tmp->remaining, &tmp->flag);
	if (tmp->remaining == NULL)
		delete_node(fd, &head);
	return (str);
}

int	main(void)
{
	char	*buff;
	int		fd1;
    int     fd2;
    int     fd3;

    fd1 = open("file1", O_RDONLY);
	if (fd1 == -1)
		printf("unable to open file\n");
    fd2 = open("file2", O_RDONLY);
	if (fd2 == -1)
		printf("unable to open file2\n");
    fd3 = open("file3", O_RDONLY);
	if (fd1 == -1)
		printf("unable to open file3\n");
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
        buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		// close(fd);
		
	return (0);
}

