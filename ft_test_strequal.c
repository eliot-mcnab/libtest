/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strequal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:15:10 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 09:39:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"
#include "libft.h"

bool	ft_test_strequal(t_unit *unit, t_str var, t_str val)
{
	if (ft_strcmp(var, val) == 0)
	{
		(unit -> passed)++;
		return (true);
	}
	else
	{
		(unit -> failed)++;
		return (false);
	}
}
