CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = Assignment_1
SRCS = Assignment_1.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Linking complete!･ﾟ✧･ﾟ"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)
	@echo "Compilation complete!･ﾟ✧･ﾟ"

test: $(TARGET)
	./$(TARGET)
	@echo "Testing complete!･ﾟ✧･ﾟ"

clean: 
	rm -f $(OBJS) $(TARGET)
	@echo "Cleanup complete!･ﾟ✧･ﾟ"

.PHONY: all run test clean