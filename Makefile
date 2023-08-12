CXX = clang++-14
CXXFLAGS = -std=c++17 -Wall -Wextra
LIB_DIR = lib
SDL2_LIBS = -lSDL2
SDL2_IMAGE_LIBS = -lSDL2_image
SDL2_TTF_LIBS = -lSDL2_ttf
autotest:
	$(CXX) $(CXXFLAGS) -o run_tests autotest.cpp -I include -L $(LIB_DIR) $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS) -Wl,-rpath,$(CURDIR)/$(LIB_DIR)
game: 
	$(CXX) $(CXXFLAGS) -o play main.cpp -I include -L $(LIB_DIR) $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS) -Wl,-rpath,$(CURDIR)/$(LIB_DIR)
clean:
	rm -f play run_tests