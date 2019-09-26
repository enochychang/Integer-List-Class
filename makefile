a.out : main.o IntList.o
	g++ main.o IntList.o 

main.o : main.cpp IntList.h
	g++ -c main.cpp

IntList.o : IntList.cpp IntList.h
	g++ -c IntList.cpp

clean :
	rm *.o a.out