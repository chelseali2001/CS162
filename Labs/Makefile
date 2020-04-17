CC = g++ -std=c++11
exe_file = lab3_exe
$(exe_file): prog.o driver.o
	$(CC) prog.o driver.o -o $(exe_file)
prog.o: prog.cpp
	$(CC) -c prog.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
