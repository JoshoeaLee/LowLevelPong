game: 
	clang++ main.cpp -o play -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0 -l SDL2_ttf-2.0.0

autotest:
	clang++ autotest.cpp -o run_tests -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0 -l SDL2_ttf-2.0.0

clean:
	rm -f play run_tests