all:hello_world.cpp
	g++ hello_world.cpp -o test.out -std=c++11 -lpthread
clean:
	rm -f hello.out
