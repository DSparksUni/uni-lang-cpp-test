IDIR = include
ODIR = obj
SDIR = src

vpath %.cpp $(SDIR)

CXX = clang++
CXXFLAGS = -I$(IDIR) -Wall -Wextra -Wno-missing-braces -Wconversion -pedantic -std=c++17 -DUNI_DEBUG
TARGET = uni

__OBJS = main error util iter lexer
OBJS = $(patsubst %,$(ODIR)/uni_%.o,$(__OBJS))

all: $(TARGET)
	@echo Build Complete!

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(ODIR)/%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm $(TARGET) $(OBJS)
