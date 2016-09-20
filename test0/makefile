CXX = g++
CFLAGS = -g -Wall -Wextra `pkg-config --cflags opencv`
LDFLAGS = `pkg-config --libs opencv`
SRCS = src/*
OUT = out

all: $(SRCS)
	$(CXX) $(CFLAGS) $(SRCS) -o $(OUT)
