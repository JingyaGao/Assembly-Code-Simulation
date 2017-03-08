CPU.out : decoder.o instruction.o labels.o main.o registers.o word.o data.o memory.o instruction2.o
	g++ -ansi -Wall -g -o CPU.out decoder.o instruction.o labels.o main.o registers.o word.o data.o memory.o instruction2.o

data.o : data.cpp data.h word.h
	g++ -ansi -Wall -g -c data.cpp

decoder.o : decoder.cpp decoder.h instruction.h registers.h 
	g++ -ansi -Wall -g -c decoder.cpp

instruction.o : instruction.cpp instruction.h 
	g++ -ansi -Wall -g -c instruction.cpp

instruction2.o : instruction2.cpp instruction2.h
	g++ -ansi -Wall -g -c instruction2.cpp

labels.o : labels.cpp labels.h instruction2.h
	g++ -ansi -Wall -g -c labels.cpp

main.o : main.cpp registers.h decoder.h instruction.h labels.h memory.h data.h
	g++ -ansi -Wall -g -c main.cpp

memory.o : memory.cpp memory.h word.h data.h
	g++ -ansi -Wall -g -c memory.cpp

registers.o : registers.cpp registers.h 
	g++ -ansi -Wall -g -c registers.cpp

word.o : word.cpp word.h
	g++ -ansi -Wall -g -c word.cpp


clean : 
	rm -f CPU.out decoder.o  instruction.o  labels.o  main.o registers.o word.o data.o memory.o instruction2.o
