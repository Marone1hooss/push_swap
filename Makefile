#-*-Makefile-*-
SRCS = main.c \
	  functions.c \
	  stack.c 

OBJS = ${SRCS:%.c=%.o}

NAME = main
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
#Linking step:
${NAME}: ${OBJS} 
	gcc ${OBJS} -o  ${NAME} $(LDFLAGS)

#Compilation step:

%.o: %.c functions.h 
	gcc  -g -c $< -o  $@ 

run: 
	main 

clean:
	rm -f *.o  main