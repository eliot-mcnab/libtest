# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 11:22:09 by emcnab            #+#    #+#              #
#    Updated: 2022/11/12 16:10:17 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# 										DISPLAY
# ==============================================================================

# colors
BLACK   = \033[0;30m
GRAY    = \033[1;30m
RED     = \033[0;31m
LRED    = \033[1;31m
GREEN   = \033[0;32m
LGREEN  = \033[1;32m
ORANGE  = \033[0;33m
YELLOW  = \033[1;33m
BLUE    = \033[0;34m
LBLUE   = \033[1;34m
PURPLE  = \033[0;35m
LPURPLE = \033[1;35m
CYAN    = \033[0;36m
LCYAN   = \033[1;36m
LGRAY   = \033[0;37m
WHITE   = \033[1;37m

# ascii art
define HEADER
$(CYAN) _____     _____  ______   _________  ________   ______   _________    $(BLUE)    *.   
$(CYAN)|_   _|   |_   _||_   _ \ |  _   _  ||_   __  |.' ____ \ |  _   _  |   $(BLUE)     *   
$(CYAN)  | |       | |    | |_) ||_/ | | \_|  | |_ \_|| (___ \_||_/ | | \_|   $(WHITE)   : :   
$(CYAN)  | |   _   | |    |  __'.    | |      |  _| _  _.____`.     | |       $(WHITE)   | |   
$(CYAN) _| |__/ | _| |_  _| |__) |  _| |_    _| |__/ || \____) |   _| |_      $(WHITE)  /   \  
$(CYAN)|________||_____||_______/  |_____|  |________| \______.'  |_____|     $(WHITE) (_____) 

$(LGRAY) - version by Eliot McNab
endef

define SEPERATOR
$(WHITE)...............................................................................
endef

export HEADER
export SEPERATOR

# ==============================================================================
# 									COMPILATION
# ==============================================================================

# .c files
define CFILES
	ft_runner_create.c	ft_runner_start.c	ft_runner_success.c	ft_test_cequal.c
	ft_test_equal.c		ft_test_strequal.c	ft_tests_success.c	ft_unit_add.c
	ft_test_message.c	ft_counter.c		ft_countfail.c		ft_countpass.c
	ft_countotal.c
endef

# .o files
ODIR = objs/
OFILES = $(patsubst %.c, $(ODIR)%.o, $(CFILES))

# .a files used by library
ADIR = ./
AFILES = libft.a

# archive compiler
AR = ar
AFLAGS = -rcs

# C compiler
CC = gcc
OPT = 0
DEBUG = -g
CFLAGS = $(DEBUG) -Wall -Wextra -Werror -O$(OPT)

# binary name
BINARY = libtest.a

# test files
TFILES = test.c
TOFILES = $(patsubst %.c, $(ODIR)%.o, $(TFILES))

# by default, builds the binary
all: display $(BINARY)

# displays header
display:
	@echo "$$HEADER"
	@echo "$$SEPERATOR"

# to buld the binary, all associated object files must have been compiled
$(BINARY): $(OFILES)
	@$(AR) $(AFLAGS) $@ $^ $(AFILES)
	@echo "$$SEPERATOR"
	@echo "${WHITE}${@} ${GREEN}built successfully!"

# for an object file to be built, the associated c file must exist
$(ODIR)%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo "${LGRAY}${@} ${GREEN}built successfully!"

# removes all .o files
clean: display
	@rm -f $(OFILES) $(TOFILES)
	@echo "${RED} all object files deleted successfully"

# removes test binary
tclean: clean
	@rm -f $(./test)
	@echo "${RED}"
	@echo "$(RED) test binary deleted"

# removes all .o files and the library binary
fclean: clean tclean
	@rm -f $(BINARY)
	@echo "${RED}"
	@echo "${LRED} ${WHITE}${BINARY} ${LRED}deleted successfully"	
	@echo "$$SEPERATOR"

# removes all generated files and re-builds the binary
re: fclean all

# to run tests, binary must first be built 
test: display buildtest	
	@echo "${LGREEN}running ${WHITE}${TFILES}${LGREEN} ..."
	@echo "$$SEPERATOR"
	@./test

# for test binary to be built, all relevant object files must be built first
buildtest: $(TOFILES) $(OFILES)
	@$(CC) $(CFLAS) -o test $^ $(AFILES)
	@echo "${WHITE}test ${GREEN}built successfully!"

# rebuilds libft and copies it over to current directory
update:
	@(cd ../libft && make)
	@cp ../libft/libft.a ./
	@cp ../libft/libft.h ./
	@echo "${LGREEN} ${WHITE}libft ${LGREEN}updated successfully"

.PHONY: all display clean tclean fclean re test buildtest update
