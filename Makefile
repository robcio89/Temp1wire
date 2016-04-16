temp: temp.o
	g++ -std=c++11 -o build/temp build/temp.o -lpthread
temp.o: temp1/main.cpp
	mkdir -p build/
	g++ -std=c++11 -c temp1/main.cpp -o build/temp.o
clean:
	rm -f temp/*.o build/temp
run:
	./build/temp
