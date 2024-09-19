tokenizer: history.o tokenizer.o uimain.o
	gcc -o tokenizer history.o tokenizer.o uimain.o

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

uimain.o: uimain.c

run:
	./tokenizer

clean:
	rm -f *.o tokenizer
