OBJS = client


all: ${OBJS}

cityClass: cityClass.h

client: cityClass.h cityClass.o

clean:
	-rm -f ${OBJS} *.o
