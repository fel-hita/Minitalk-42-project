# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 17:48:37 by nouhaddo          #+#    #+#              #
#    Updated: 2019/02/03 20:39:14 by nouhaddo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

all :
	make -C libft
	gcc -Wall -Wextra -Werror server.c libft/libft.a -o $(NAME1)
	gcc -Wall -Wextra -Werror client.c libft/libft.a -o $(NAME2)

clean :
	make clean -C libft 
	rm -rf client.o server.o

fclean : clean
	make fclean -C libft
	rm -rf $(NAME1) $(NAME2)

re : fclean all
