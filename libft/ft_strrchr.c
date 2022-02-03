/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:38:38 by user              #+#    #+#             */
/*   Updated: 2022/01/25 00:38:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*u_s;
	unsigned char	u_c;
	size_t			len;

	u_s = (unsigned char *)s;
	u_c = (unsigned char)c;
	len = ft_strlen(s);
	while (len)
	{
		if (u_s[len] == u_c)
			break ;
		len--;
	}
	if (u_s[len] == u_c)
		return ((char *)&u_s[len]);
	return (NULL);
}
