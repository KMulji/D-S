exec: main.o ArrayADT.o
	g++ -o exec main.o ArrayADT.o

main.o: main.cpp
	g++ -c -ggdb3 main.cpp

ArrayADT.o: ArrayADT.cpp
	g++ -c -ggdb3 ArrayADT.cpp

clean:
	rm -f *~ *.o *.a
#^^^This space must be a TAB!!.