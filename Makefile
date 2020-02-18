run: build
	./markov
build:
	g++ -std=c++11 src/main.cpp src/markov.cpp -o markov
