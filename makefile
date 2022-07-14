objects = ls.o mv.o cat.o stringLinkedList.o main.o

CFLAGS = -Wall

release : $(objects)
	gcc $(CFLAGS) -o xshell $(objects)

build : $(objects)
	$(eval CFLAGS = -Wall -g)
	gcc $(CFLAGS) -o xshell $(objects)

cat.o : cat.c cat.h
	gcc $(CFALGS) -c cat.c
	
mv.o : mv.c mv.h
	gcc $(CFLAGS) -c mv.c

ls.o : ls.c ls.h
	gcc $(CFLAGS) -c ls.c

stringLinkedList.o : stringLinkedList.c stringLinkedList.h extensions.h
	gcc $(CFLAGS) -c stringLinkedList.c

main.o : main.c stringLinkedList.h extensions.h
	gcc $(CFLAGS) -c main.c

