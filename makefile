all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/DogruKuyruk.cpp -o ./lib/DogruKuyruk.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/DugumTree.cpp -o ./lib/DugumTree.o
	g++ -c -I "./include" ./src/treeAVL.cpp -o ./lib/treeAVL.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/main.o ./lib/DogruKuyruk.o ./lib/Dugum.o ./lib/DugumTree.o ./lib/treeAVL.o -o ./bin/program
calistir:
	./bin/program.exe