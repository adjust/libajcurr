.POSIX:

LIBPATH?=/lib
INCPATH?=/usr/include
MANPATH?=/usr/share/man

default: libajcurr.a(ajcurr.o)
ajcurr.o: ajcurr.h codes.h

ajcurr.h: ajcurr.in codes.h gencurr
	./gencurr ajcurr.in codes.h > $@

clean:
	rm -f ajcurr.h test *.a *.o

install: libajcurr.a ajcurr.h
	cp libajcurr.a $(LIBPATH)
	cp ajcurr.h $(INCPATH)
	cp man3/* $(MANPATH)/man3/
	cp man7/* $(MANPATH)/man7/

test: test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -L. -lajcurr -static -o $@
	./test
