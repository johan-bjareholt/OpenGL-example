
NAME=game
VERSION=0.1

LIBS=-lGL -lGLEW -lSDL2
INCLUDES=-I./include
CPPFLAGS=-g $(LIBS) $(INCLUDES)

SRCF=main.cpp display.cpp shader.cpp mesh.cpp input.cpp texture.cpp camera.cpp
SRC=$(patsubst %.cpp,src/%.cpp,$(SRCF))
OBJ=$(patsubst %.cpp,obj/%.o,$(SRCF))

.PHONY: all
all: $(OBJ)
	$(CXX) -o $(NAME) $(CPPFLAGS) $(OBJ)

.PHONY: clean
clean:
	rm -rf obj
	rm -f $(NAME)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) -o $@ -c $(CPPFLAGS) $<

