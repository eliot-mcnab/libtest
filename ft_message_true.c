/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_true.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:21:29 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:29:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Generates a message summarising the result of a boolean test.
 *
 * @param str_var (t_str): string representation of the variable that was
 * 	tested.
 * @param success (bool): true if [str_var] was true.
 *
 * @return (t_str): " [str_var] should equalbe true - [str_success]"
 */
char	*ft_message_true(t_str str_var, bool success)
{
	t_str	str_success;

	if (success)
	{
		str_success = SUCCEESS;
	}
	else
	{
		str_success = FAILURE;
	}
	return (ft_strnjoin(9,
			LPURPLE, " ", WHITE, "\"", str_var, "\"", LGRAY,
			" should be true - ", str_success));
}
