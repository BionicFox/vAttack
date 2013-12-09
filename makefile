all:
	g++ -o vAttack.exe main.cpp main.h game.cpp game.h baseFunctions.cpp baseFunctions.h base64.cpp base64.h -static-libstdc++ -static-libgcc