CC=g++
CFLAGS=-I../sndfile/ -std=c++11
#LDFLAGS= -lsndfile
LDFLAGS= -lsndfile -L../sndfile/

all:
	$(CC) -o melody melody.cpp $(CFLAGS) $(LDFLAGS)

