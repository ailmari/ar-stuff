CXX=g++
SRCS=src/*
OUT=out

all: $(SRCS)
		$(CXX) $(SRCS) -o $(OUT)