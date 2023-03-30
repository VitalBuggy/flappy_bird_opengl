# optional flags (if the compiler supports it)
CXXFLAGS += -std=c++11

# HIGHLY RECOMMENDED flags
CXXFLAGS += -Wall -Wextra -pedantic-errors

# required for SFML programs
LDLIBS := $(shell pkg-config sfml-all --libs)

# The rest will turn any source file ending in .cpp
# into a program of the same name

SRCDIR := src
BUILDDIR := build

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
PROGRAMS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%,$(SOURCES))

all: $(PROGRAMS)

$(BUILDDIR)/%: $(SOURCES)
	$(CXX) $(CXXFLAGS) $< $(LDLIBS) -o $@

clean:
	$(RM) $(BUILDDIR)/*
