CC = g++
CFLAGS = -O3 -ffast-math
VFLAGS = --std=c++17
LDFLAGS = -pthread -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
CDFLAGS = -g
TARGET = fairAintSquare.exe
DTARGET = d_airAintSquare.exe 
WARNINGS = -pedantic -Wall -Wextra
CPP = main.cpp

all:
	$(CC) $(WARNINGS) $(VFLAGS) $(CFLAGS) $(CPP) $(LDFLAGS) -o $(TARGET)

windows:
	$g++ -O3 -std=c++14 main.cpp -o Finneon.exe -lsfml-graphics -lsfml-window -lsfml-system -lGL

debug:
	$(CC) $(WARNINGS) $(VFLAGS) $(CDFLAGS) $(CPP) $(LDFLAGS) -o $(DTARGET)

documentation:
	pdflatex gameDesignDoc.tex

clean:
	rm -rf $(TARGET) $(DTARGET) *.aux *.log *.pdf *.toc
