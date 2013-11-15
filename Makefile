CC = gcc 	# Compiler to use
OPTIONS = -O2 -g -Wall  # -g for debug, -O2 for optimise and -Wall additional messages
NCUSES_FLAGS = -lncurses
INCLUDES = -I . # Directory for header file
OBJS = main.o	# List of objects to be build
.PHONY: all clean 

all: ${OBJS}
	@echo "Building.." 
	${CC} ${OPTIONS} ${INCLUDES} ${OBJS} ${NCUSES_FLAGS} -o tictac

%.o: %.c  
	${CC} ${OPTIONS} -c $*.c ${INCLUDES}  ${NCUSES_FLAGS}

clean:
	@echo "Cleaning up.."
	-rm -rf *.o 	# - prefix for ignoring errors and continue execution
	-rm tictac a.out
