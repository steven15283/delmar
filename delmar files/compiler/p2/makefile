frontEnd: parser.o scanner.o token.o main.o 
	g++ -std=c++11 parser.o scanner.o token.o main.o -o frontEnd

scanner.o: scanner.cpp
	g++ -c -std=c++11  scanner.cpp

parser.o: parser.cpp
	g++ -c -std=c++11  parser.cpp

token.o: token.cpp
	g++ -c -std=c++11 token.cpp
	
main.o: main.cpp
	g++ -c -std=c++11 main.cpp

clean:
	rm -rf *.o frontEnd
