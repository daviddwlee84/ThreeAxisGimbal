# Compile pid test

all:
	g++ -c PID.cpp -o PID.o
	g++ pid_test.cpp PID.o -o pid_test.out

clean:
	rm PID.o pid_test.out
