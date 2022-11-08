HashT: HT.o
	g++ HT.o -o HashT

HT.o: HT.cpp HT.h
	g++ -c HT.cpp
clean:
	rm -f *.o
	rm HashT
run: HashT
	./HashT

