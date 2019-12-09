
CMP = g++ -std=c++11 -Wall
CLASS = crossboard
MAIN = crossword
EXEC = crossword

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) -g $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c -g $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c -g $(MAIN).cpp -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)

