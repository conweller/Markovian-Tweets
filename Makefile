run: markov
	./markov

markov: main.o markov.o
	g++ -std=c++11 main.o markov.o -o markov

main.o: src/main.cpp
	g++ -c -std=c++11 src/main.cpp

markov.o: src/markov.cpp
	g++ -c -std=c++11 src/markov.cpp

clean:
	rm *.o markov
