CXX = g++

CFLAGS = -g `pkg-config --cflags opencv`
LDFLAGS = `pkg-config --libs opencv`

SRCS = src/*
OUT = out

all: $(SRCS)
	$(CXX) $(LDFLAGS) $(CFLAGS) $(SRCS) -o $(OUT)