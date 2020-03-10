helpers/helper: obj/main.o obj/markov.o
	g++ -std=c++11 obj/main.o obj/markov.o -o helpers/helper

obj/main.o: src/main.cpp
	g++ -c -std=c++11 src/main.cpp -o obj/main.o

obj/markov.o: src/markov.cpp
	g++ -c -std=c++11 src/markov.cpp -o obj/markov.o

clean:
	rm obj/*.o helpers/helper
