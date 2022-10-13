/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:51:07 by nali              #+#    #+#             */
/*   Updated: 2021/12/10 15:51:07 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	if (*str == c)
	{
		return (str);
	}
	return (NULL);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	int	i;
	int	slen;

	i = 0;
	slen = 0;
	while (src[slen])
		slen++;
	if (dstsize > 0)
	{
		while (src[i] && dstsize - 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	return (slen);
}

char	*str_concat(char *s1, const char *s2)
{
	int		l1;
	int		l2;
	char	*str;
	int		i;
	int		j;

	l1 = 0;
	l2 = 0;
	while (s1[l1])
		l1++;
	while (s2[l2])
		l2++;
	str = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	i = ft_strlcpy(str, s1, l1 + l2 + 1);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free((void *)s2);
	return (str);
}

t_GNL	*ft_lstnew(int fd)
{
	t_GNL	*new;

	new = (t_GNL *)malloc(sizeof(t_GNL));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->flag = 0;
	new->remaining = NULL;
	new->next = NULL;
	return (new);
}

void	delete_node(int fd, t_GNL **head)
{
	t_GNL	*temp;
	t_GNL	*prev;

	if ((*head)->fd == fd)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return ;
	}
	temp = *head;
	while (temp->fd != fd)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}
