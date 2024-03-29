# Makefile used to compile the project ram-simulator.
# Author: Cristian Abrante Dorta.

# Varibles used for the compilation.
CXX = g++
BINARY = ram-simulator

IDIR = include
ODIR = obj

_DEPS = arithmetical-logical-unit.h control-unit.h data-memory.h input-tape.h instruction.h memory-unit.h operand.h output-tape.h program-memory.h random-access-machine.h tape-unit.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o arithmetical-logical-unit.o control-unit.o data-memory.o input-tape.o instruction.o memory-unit.o operand.o output-tape.o program-memory.o random-access-machine.o tape-unit.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

CXXFLAGS = -g -std=c++14 -I$(IDIR)

# If any option is selected the program will build.
all: $(BINARY)

# Creation of objects under obj/ folder.
$(ODIR)/%.o: src/%.cpp $(DEPS)

		@if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

		$(CXX) -c -o $@ $< $(CXXFLAGS)

# Compilation of the binary program.
$(BINARY): $(OBJ)
		$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f $(ODIR)/*.o $(BINARY)
	rm -r $(ODIR)
