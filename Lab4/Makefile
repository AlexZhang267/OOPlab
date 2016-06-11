OBJS= test.o func.o
run: $(OBJS)
	g++ -o run $(OBJS)

func.o: func.cpp
test.o: test.cpp

clean:
	rm -f *.o run
