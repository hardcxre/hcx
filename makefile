CFLAGS = -ansi -pedantic -Wall -Werror -o3

libhcx.a: binary.o class.o ternary.o unary.o
	ar rcs libhcx.a *.o

clean:
	rm -f *~ .*~ *.o libhcx.a
