/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:52:44 by nali              #+#    #+#             */
/*   Updated: 2021/12/10 15:52:44 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct get_next_line
{
	int						fd;
	int						flag;
	char					*remaining;
	struct get_next_line	*next;
}	t_GNL;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

char			*get_next_line(int fd);
int				ft_findlen(const char *s);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
char			*ft_strchr(char *str, int c);
char			*str_concat(char *s1, const char *s2);
t_GNL			*ft_lstnew(int fd);
void			delete_node(int fd, t_GNL **head);

#endif