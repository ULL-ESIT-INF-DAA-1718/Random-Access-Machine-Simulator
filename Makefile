# Makefile used to compile the project ram-simulator.
# Author: Cristian Abrante Dorta.

# Varibles used for the compilation.
CXX = g++
BINARY = ram-simulator

IDIR = include
ODIR = obj

_DEPS = 
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

CXXFLAGS = -g -std=c++14 -I$(IDIR)

# If any option is selected the program will build.
all: $(BINARY)

# Creation of objects under obj/ folder.
$(ODIR)/%.o: src/%.cc $(DEPS)

		@if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

		$(CXX) -c -o $@ $< $(CXXFLAGS)

# Compilation of the binary program.
$(BINARY): $(OBJ)
		$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f $(ODIR)/*.o $(BINARY)
	rm -r $(ODIR)