bin/helper: obj/main.o obj/markov.o
	g++ -g -std=c++11 obj/main.o obj/markov.o -o bin/helper

obj/main.o: src/main.cpp
	g++ -g -c -std=c++11 src/main.cpp -o obj/main.o

obj/markov.o: src/markov.cpp
	g++ -g -c -std=c++11 src/markov.cpp -o obj/markov.o

clean:
	rm obj/*.o bin/helper
