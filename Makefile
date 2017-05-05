COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

OBJS = ./bin/base.o ./bin/builder.o ./bin/call ./bin/cleanup.o 

all: ./src/main.cpp $(OBJS) 
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/rshell
	 
./bin/base.o: ./src/base.h ./src/base.cpp
		$(COMPILE) $(FLAGS) -c ./src/base.cpp -o ./bin/base.o
		
./bin/builder.o: ./src/base.h ./src/builder.h ./src/builder.cpp
		$(COMPILE) $(FLAGS) -c ./src/builder.cpp -o ./bin/builder.o
		
./bin/call.o: ./src/base.h ./src/call.h ./src/call.cpp
		$(COMPILE) $(FLAGS) -c ./src/call.cpp -o ./bin/call.o
		
./bin/cleanup.o: ./src/base.h ./src/cleanup.h ./src/cleanup.cpp
		$(COMPILE) $(FLAGS) -c ./src/cleanup.cpp -o ./bin/cleanup.o
	 
clean:
		rm -rf ./bin/
	 
	 
	
