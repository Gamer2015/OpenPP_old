#Select Operating System
OS = WIN
#OS = UNIX

MODULES = SDL2 Box2D


#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -std=c++11


#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 

ifneq (, $(findstring Box2D, $(MODULES)))
	LINKER_FLAGS += -lBox2D
endif

ifneq (, $(findstring SDL2, $(MODULES)))
	LINKER_FLAGS += -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
endif

ifneq (, $(findstring SFML, $(MODULES)))
	LINKER_FLAGS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
	ifeq ($(OS),WIN)
		LINKER_FLAGS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
	endif
endif

ifeq ($(OS),WIN)
	INCLUDE_PATHS = -IC:/Softwareentwicklung/C++/include/
	LIBRARY_PATHS = -LC:/Softwareentwicklung/C++/lib/
else ifeq ($(OS),UNIX)
	INCLUDE_PATHS = -I/usr/include/
	LIBRARY_PATHS = -L/usr/lib/
endif


#OBJS specifies which files to compile as part of the project
OBJS = $(wildcard *.cpp) 
OBJS += $(wildcard Game/*.cpp)
OBJS += $(wildcard ../Core/Math/*.cpp)  $(wildcard ../Core/Exceptions/*.cpp) $(wildcard ../Core/*.cpp)


#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Test.exe


#This is the target that compiles our executable
all: $(OBJS)	
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)