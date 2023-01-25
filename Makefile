urlogv: URLogV.o ErrorHandler.o LogFile.o Parser.o
	mkdir -p bin
	g++ obj/URLogV.o obj/ErrorHandler.o obj/LogFile.o obj/Parser.o -o bin/urlogv

URLogV.o: src/URLogV.cpp
	mkdir -p obj
	g++ -c src/URLogV.cpp -o obj/URLogV.o

ErrorHandler.o: src/ErrorHandler.cpp
	g++ -c src/ErrorHandler.cpp -o obj/ErrorHandler.o

LogFile.o: src/LogFile.cpp
	g++ -c src/LogFile.cpp -o obj/LogFile.o

Parser.o: src/Parser.cpp
	g++ -c src/Parser.cpp -o obj/Parser.o

clean:
	rm obj/*.o bin/urlogv