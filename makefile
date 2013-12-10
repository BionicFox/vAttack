all:
	g++ -o vAttack.exe main.cpp main.h game.cpp game.h baseFunctions.cpp baseFunctions.h -static-libstdc++ -static-libgcc