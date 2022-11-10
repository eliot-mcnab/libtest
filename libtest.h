/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/10 18:14:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

#include "libft.h"

typedef struct s_runner
{
	t_list	*units;
}	t_runner;

typedef struct s_unit
{
	t_list	*test;
	size_t	passed;
}	t_unit;

#endif
