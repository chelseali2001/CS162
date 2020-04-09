CC = g++ -std=c++11
exe_file = lab2_prog
$(exe_file): student_db.o driver.o
	$(CC) student_db.o driver.o -o $(exe_file)
student_db.o: student_db.cpp
	$(CC) -c student_db.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
