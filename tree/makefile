CXX=g++
CXXFLAGS=-Wall -g
SRC = tree.cc test.cc
ODIR = build
DEPS = tree.h

_OBJ = tree.o test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

TARGET=main.out

$(ODIR)/%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f $(ODIR)/*.o $(TARGET)
