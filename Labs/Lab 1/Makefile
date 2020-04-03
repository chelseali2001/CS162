CC = g++
exe_file = multi_div
$(exe_file): multi_div.o prog.o
	$(CC) multi_div.o prog.o -o $(exe_file)
mult_div.o: multi_div.cpp
	$(CC) -c multi_div.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *.out *.o $(exe_file)
