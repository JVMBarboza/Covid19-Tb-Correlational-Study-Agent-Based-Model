TARGET=exec
TARGETBETA=betaCalc
CC=g++
LD=g++
CCFLAGS=
OBJS=main.o person.o
OBJSBETA=generateBeta.o person.o


exec:$(OBJS)
	$(LD) $(OBJS) -o $(TARGET) $(CCFLAGS)
 

betaCalc:$(OBJSBETA)
	$(LD) $(OBJSBETA) -o $(TARGETBETA) $(CCFLAGS)


main.o: src/main.cpp
	$(CC) src/main.cpp -o main.o -c $(CCFLAGS)  
 
person.o: src/person.cpp
	$(CC) src/person.cpp -o person.o -c $(CCFLAGS)

generateBeta.o: src/generateBeta.cpp
	$(CC) src/generateBeta.cpp -o generateBeta.o -c $(CCFLAGS)


clean:
	rm -rf *.o exe* betaCalc *.cpp *.h output.txt