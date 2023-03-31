# Compiler and linker settings
ifeq ($(shell uname -s), Darwin)
    ifeq ($(shell uname -p), arm)
        CC = arch -x86_64 g++
    else
        CC = g++
    endif
    CFLAGS = -I/usr/local/Cellar/sfml/2.5.1_2/include
    LDFLAGS = -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-audio -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system
else
    CC = g++
    CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic-errors
    LDLIBS := $(shell pkg-config sfml-all --libs)
endif

# Directories and files
SRCDIR := src
BUILDDIR := build
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
PROGRAM := $(BUILDDIR)/prog

# Targets
all: $(PROGRAM)

$(PROGRAM): $(SOURCES)
	$(CC) $(CFLAGS) $(CXXFLAGS) $^ $(LDFLAGS) -o $(PROGRAM)

clean:
	$(RM) $(PROGRAM)
