/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:38:38 by user              #+#    #+#             */
/*   Updated: 2022/01/25 00:38:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shutdown(void)
{
	vals_storage(NULL, NULL, NULL, NULL);
	exit(EXIT_FAILURE);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	shutdown();
}
