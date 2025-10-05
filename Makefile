all:
	g++ -o racelife src/main.cpp -lgb -lSDL2 -lSDL2_ttf
	chmod +x racelife
