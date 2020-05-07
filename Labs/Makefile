CC = g++ -std=c++11

exe_file = lab6_exe

$(exe_file): shape.o rectangle.o circle.o square.o application.o
	$(CC) shape.o rectangle.o circle.o square.o application.o -o $(exe_file)
shape.o: shape.cpp
	$(CC) -c shape.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
square.o: square.cpp
	$(CC) -c square.cpp
application.o: application.cpp
	$(CC) -c application.cpp
clean:
	rm -f *.out *.o $(exe_file)