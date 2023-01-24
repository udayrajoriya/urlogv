urlogv: EntryPoint.o ErrorHandler.o LogFile.o Parser.o
	g++ EntryPoint.o ErrorHandler.o  LogFile.o Parser.o -o urlogv

EntryPoint.o: EntryPoint.cpp
	g++ -c EntryPoint.cpp

ErrorHandler.o: ErrorHandler.cpp
	g++ -c ErrorHandler.cpp

LogFile.o: LogFile.cpp
	g++ -c LogFile.cpp

Parser.o: Parser.cpp
	g++ -c Parser.cpp

clean:
	rm *.o urlogv
