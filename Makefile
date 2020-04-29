INC = -I ./Headers/

executable: main.o Quaternion.o DualQuaternion.o
	g++ main.o Quaternion.o DualQuaternion.o

main.o : main.cpp Headers/Quaternion.h Headers/DualQuaternion.h
	g++ $(INC) -c main.cpp

Quaternion.o: Quaternion.cpp Headers/Quaternion.h
	g++ $(INC) -c Quaternion.cpp

DualQuaternion.o: DualQuaternion.cpp Headers/DualQuaternion.h
	g++ $(INC) -c DualQuaternion.cpp

clean:
	rm Quaternion.o DualQuaternion.o main.o a.out
