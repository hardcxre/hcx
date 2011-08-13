libhardcxre.a: class.o
	ar rcs libhardcxre.a *.o

clean:
	rm -f *~ .*~
	rm -f *.o
	rm -f libhardcxre.a
