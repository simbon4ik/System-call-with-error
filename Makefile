all: prog.o
	gcc prog.o -o prog -g  #Здесь можно добавить флаг компиляции --std=gnu11 если хотим использовать sys_errlist

prog.o: prog.c 
	gcc -c prog.c 

clean:
	rm -f *.o
	
