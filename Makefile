SDL2_LIBS = -l SDL2-2.0.0
SDL2_IMAGE_LIBS = -l SDL2_image-2.0.0
SDL2_TTF_LIBS = -l SDL2_ttf-2.0.0

game: 
	clang++ main.cpp -o play -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)

autotest:
	clang++ autotest.cpp -o run_tests -I include -L lib $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)

clean:
	rm -f play run_tests