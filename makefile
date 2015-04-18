test: Queue.cc
	g++ -o main tests/Queue_Test.cc Queue.cc -lm -g
	./main
	rm main

remove:
	rm main
