SDL2_LIBS = -l SDL2
SDL2_IMAGE_LIBS = -l SDL2_image
SDL2_TTF_LIBS = -l SDL2_ttf
autotest:
	clang++ autotest.cpp -o run_tests -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
game: 
	clang++ main.cpp -o play -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
clean:
	rm -f play run_tests