/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:59:34 by huweber           #+#    #+#             */
/*   Updated: 2016/11/16 19:54:02 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = -1;
	while (s[++i])
		;
	return (i);
}
