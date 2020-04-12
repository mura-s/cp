CPP = g++
CPPFLAGS = -Wall -Wextra -O2 -std=gnu++17

TARGET = main
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

.PHONY: fmt
fmt:
	clang-format -i *.cpp

.PHONY: test
test:
	./test.sh

.PHONY: clean
clean:
	rm -rf *.o $(TARGET) $(TARGET).dSYM
