SDL2_LIBS = -lSDL2
SDL2_IMAGE_LIBS = -lSDL2_image
SDL2_TTF_LIBS = -lSDL2_ttf
autotest:
	clang++-14 -std=c++17 -Wall -Wextra -o run_tests autotest.cpp -I include -L lib -Wl,-rpath='$$ORIGIN/lib' -lSDL2 -lSDL2_image -lSDL2_ttf
game: 
	clang++ -v main.cpp -o play -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
clean:
	rm -f play run_tests
