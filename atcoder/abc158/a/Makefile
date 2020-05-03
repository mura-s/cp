CPP = clang++
CPPFLAGS = -std=c++17 -stdlib=libc++ -Wall -O2

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
