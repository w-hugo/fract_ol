/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:43:38 by huweber           #+#    #+#             */
/*   Updated: 2017/01/30 15:52:57 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 4096

typedef struct			s_gnl
{
	char				*save;
	int					fd;
	int					len;
	int					eof;
	struct s_gnl		*next;
}						t_gnl;

void					*ft_realloc(void *p, size_t size);
int						free_all(t_list **lst, int fd, char **line, char *tmp);
t_gnl					*init_gnl(t_list **lst, int fd);
int						parse_line(t_gnl *gnl, char **line);
int						read_line(t_gnl *gnl, char **line, char *tmp);
int						get_next_line(int fd, char **line);

#endif
