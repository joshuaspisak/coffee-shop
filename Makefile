CC=g++ -std=c++11
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): coffee.o order.o menu.o shop.o prog.cpp
	$(CC) coffee.o order.o menu.o shop.o prog.cpp -o $(EXE_FILE)

coffee.o: coffee.cpp
	$(CC) -c coffee.cpp

order.o: order.cpp
	$(CC) -c order.cpp

menu.o: menu.cpp
	$(CC) -c menu.cpp

shop.o: shop.cpp
	$(CC) -c shop.cpp

clean:
	rm -f *.o $(EXE_FILE)