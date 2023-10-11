files = src/myshell.c src/utility.c src/shellcontainer.c
objects = $(patsubst src/%.c,%.o,$(files))

myshell:
	mkdir -p bin
	gcc -c $(files)
	gcc -o bin/$@ $(objects)
	mv $(objects) bin/
	

clean: #cleans the bin folder
	rm bin/*.o
	rm bin/myshell

.PHONY: myshell
