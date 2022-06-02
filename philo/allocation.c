/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:36:21 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/05/24 21:42:37 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_any_alloc(size_t size, size_t len)
{
	void	*ptr;

	ptr = malloc(size * len);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, size * len);
	return (ptr);
}
