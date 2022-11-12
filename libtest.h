/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:41:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include "libft.h"
#include <stddef.h>

# define BLACK    "\033[0;30m"
# define GRAY     "\033[1;30m"
# define RED      "\033[0;31m"
# define LRED     "\033[1;31m"
# define GREEN    "\033[0;32m"
# define LGREEN   "\033[1;32m"
# define ORANGE   "\033[0;33m"
# define YELLOW   "\033[1;33m"
# define BLUE     "\033[0;34m"
# define LBLUE    "\033[1;34m"
# define PURPLE   "\033[0;35m"
# define LPURPLE  "\033[1;35m"
# define CYAN     "\033[0;36m"
# define LCYAN    "\033[1;36m"
# define LGRAY    "\033[0;37m"
# define WHITE    "\033[1;37m"
# define SUCCEESS "\033[0;32msuccess  \033[0;37m"
# define FAILURE  "\033[0;31mfailure  \033[0;37m"

/*
TODO: refactor counting data to t_counter strcuture
TODO: add custom methods for counting rather than manual incrementation
TODO: add nequal (not equal) method\
TODO: add more comparison methods */

typedef struct s_counter
{
	size_t	passed;
	size_t	failed;
	double	threshold;
}	t_counter;

typedef struct s_runner
{
	t_list		*units_head;
	t_list		*units_last;
	t_counter	*counter;
}	t_runner;

typedef struct s_unit
{
	t_runner	*runner;
	t_str		name;
	double		(*f_tests)(struct s_unit *);
	t_counter	*counter;
}	t_unit;

typedef double	(*t_tests)(t_unit*);

t_runner	*ft_runner_create(double threshold);
void		ft_unit_add(t_runner *runner, t_str unit_name, t_tests f_unit_test,
		double threshold);
void		ft_runner_start(t_runner *runner);
bool		ft_test_equal(t_unit *unit, size_t var, size_t val);
bool		ft_test_strequal(t_unit *unit, t_str var, t_str val);
bool		ft_test_cequal(t_unit *unit, t_any var, t_any val, t_conv *conv);
double		ft_runner_success(t_runner *runner);
char		*ft_test_message(t_str str_var, t_str str_val, bool success);

// counting
t_counter	*ft_counter(double threshold);
void		ft_countpass(t_counter *counter);
void		ft_countfail(t_counter *counter);
size_t		ft_countotal(t_counter *counter);
double		ft_coverage(t_counter *counter);
bool		ft_coverage_reached(t_counter *counter);
double		ft_coverage(t_counter *counter);

#endif
