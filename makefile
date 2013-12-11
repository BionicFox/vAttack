all:
	g++ main.cpp main.h game.cpp game.h baseFunctions.cpp baseFunctions.h
windows:
	g++ -o vAttack.exe main.cpp main.h game.cpp game.h baseFunctions.cpp baseFunctions.h -static-libstdc++ -static-libgcc
linux:
	g++ -o vAttack main.cpp main.h game.cpp game.h baseFunctions.cpp baseFunctions.h
mac:
	#IS THIS A COMMENT? IDK BUT ITS HERE. I'm going to continue assuming this is a comment. We don't have anyone to build on mac..so...yeah....