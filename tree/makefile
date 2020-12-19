CXX=g++
CXXFLAGS=-Wall -g -std=c++17
SRC = test.cc
ODIR = build
DEPS = tree.h util.h

_OBJ = test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

TARGET=main.out

$(ODIR)/%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f $(ODIR)/*.o $(TARGET)
