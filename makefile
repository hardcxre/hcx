CFLAGS=-ansi -o3 -Wall -Werror

libhardcxre.a: binary.o class.o ternary.o unary.o
	ar rcs libhardcxre.a *.o

clean:
	rm -f *~ .*~
	rm -f *.o
	rm -f libhardcxre.a
