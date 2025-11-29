# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Source and target
SRCS = test.cpp ../../src/renderer.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = chess

# Optional variable from command line
CUSTOM_FLAG ?= -DDEFAULT_FLAG

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CUSTOM_FLAG) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CUSTOM_FLAG) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
