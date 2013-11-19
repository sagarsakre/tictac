all:
	gcc main.c main.h vsComputer.c lib.c
clean:	
	@echo "Cleaning up.."
	-rm -rf *.o 	# - prefix for ignoring errors and continue execution
	-rm tictac a.out
	$(shell clear)
