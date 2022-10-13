exec: main.o ArrayADT.o
	g++ -o exec main.o ArrayADT.o

main.o: main.cpp
	g++ -c main.cpp

ArrayADT.o: ArrayADT.cpp
	g++ -c ArrayADT.cpp

clean:
	rm -f *~ *.o *.a
#^^^This space must be a TAB!!.