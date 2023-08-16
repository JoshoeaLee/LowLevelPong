SDL2_LIBS = -lSDL2
SDL2_IMAGE_LIBS = -lSDL2_image
SDL2_TTF_LIBS = -lSDL2_ttf
autotest:
	clang++ -v src/autotest.cpp -o run_tests -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
game: 
	clang++ -v src/main.cpp src/vec2d.cpp src/ball.cpp -o play -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
clean:
	rm -f play run_tests
