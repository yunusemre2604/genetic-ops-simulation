hepsi:derle calistir

# Derleme işlemi icin
derle: 	
	g++ -I ./include/ -o ./lib/Gen.o -c ./src/Gen.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp
	g++ -I ./include/ -o ./lib/TumIslemler.o -c ./src/TumIslemler.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/Gen.o ./lib/Kromozom.o ./lib/TumIslemler.o ./src/main.cpp

# Programı calistirmak icin
calistir:
	./bin/Program

