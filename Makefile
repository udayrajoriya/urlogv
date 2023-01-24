urlogv: URLogV.o ErrorHandler.o LogFile.o Parser.o
	g++ URLogV.o ErrorHandler.o LogFile.o Parser.o -o urlogv

URLogV.o: URLogV.cpp
	g++ -c URLogV.cpp

ErrorHandler.o: ErrorHandler.cpp
	g++ -c ErrorHandler.cpp

LogFile.o: LogFile.cpp
	g++ -c LogFile.cpp

Parser.o: Parser.cpp
	g++ -c Parser.cpp

clean:
	rm *.o urlogv