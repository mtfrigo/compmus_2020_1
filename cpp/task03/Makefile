CC=g++
CFLAGS=-I../sndfile/ -std=c++11
#LDFLAGS= -lsndfile 
LDFLAGS= -lsndfile -L../sndfile/

all:
	$(CC) -o print_freq_table print_freq_table.cpp $(CFLAGS) $(LDFLAGS)

