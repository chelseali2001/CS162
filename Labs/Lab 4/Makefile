CC = g++ -std=c++11
exe_file = lab4_exe
$(exe_file): prog.o lab4.o
	$(CC) prog.o lab4.o -o $(exe_file)
prog.o: prog.cpp
	$(CC) -c prog.cpp
lab4.o: lab4.cpp
	$(CC) -c lab4.cpp
clean:
	rm -f *.out *.o $(exe_file)
