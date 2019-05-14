CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = numGuess.cpp

vector: ${SRC}
	${CXX} ${CXXFLAGS} ${SRCS} -o numGuess