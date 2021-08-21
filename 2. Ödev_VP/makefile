ALL: Compile Execute

Compile:file person stack library node main
	g++  ./lib/file.o ./lib/person.o ./lib/stack.o ./lib/library.o ./lib/node.o ./lib/main.o -o ./bin/program 
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
library:
	g++ -I "./include" -c ./src/library.cpp -o ./lib/library.o
file:
	g++ -I "./include" -c ./src/file.cpp -o ./lib/file.o
person:
	g++ -I "./include" -c ./src/person.cpp -o ./lib/person.o
stack:
	g++ -I "./include" -c ./src/stack.cpp -o ./lib/stack.o		
node:
	g++ -I "./include" -c ./src/node.cpp -o ./lib/node.o		
Execute:
	./bin/program
