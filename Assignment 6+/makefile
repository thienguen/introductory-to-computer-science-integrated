OBJS1	= main01.o polynomial.o
OBJS2	= main02.o polynomial.o
OBJS3	= main03.o polynomial.o
OBJS4	= main04.o polynomial.o
OBJS5	= main05.o polynomial.o
OBJS6	= main06.o polynomial.o
OBJS7	= FinalBoss.o polynomial.o
CC		= g++
CCFLAGS	=
MAIN_DEPS	= polynomial.h

all: main01 main02 main03 main04 main05 main06 FinalBoss

Final: FinalBoss

main01: $(OBJS1)
	$(CC) $(CCFLAGS) -o m01 $(OBJS1)

main01.o: main01.cpp
	$(CC) $(CCFLAGS) -c main01.cpp $(MAIN_DEPS)

main02: $(OBJS2)
	$(CC) $(CCFLAGS) -o m02 $(OBJS2)

main02.o: main02.cpp
	$(CC) $(CCFLAGS) -c main02.cpp $(MAIN_DEPS)

main03: $(OBJS3)
	$(CC) $(CCFLAGS) -o m03 $(OBJS3)

main03.o: main03.cpp
	$(CC) $(CCFLAGS) -c main03.cpp $(MAIN_DEPS)

main04: $(OBJS4)
	$(CC) $(CCFLAGS) -o m04 $(OBJS4)

main04.o: main04.cpp
	$(CC) $(CCFLAGS) -c main04.cpp $(MAIN_DEPS)

main05: $(OBJS5)
	$(CC) $(CCFLAGS) -o m05 $(OBJS5)

main05.o: main05.cpp
	$(CC) $(CCFLAGS) -c main05.cpp $(MAIN_DEPS)

main06: $(OBJS6)
	$(CC) $(CCFLAGS) -o m06 $(OBJS6)

main06.o: main06.cpp
	$(CC) $(CCFLAGS) -c main06.cpp $(MAIN_DEPS)

FinalBoss: $(OBJS7)
	$(CC) $(CCFLAGS) -o FinalBoss $(OBJS7)

FinalBoss.o: FinalBoss.cpp
	$(CC) $(CCFLAGS) -c FinalBoss.cpp $(MAIN_DEPS)

polynomial.o: polynomial.cpp
	$(CC) $(CCFLAGS) -c polynomial.cpp 

# -----
# clean by removing object files.

clean:
	rm m01 main01.o
	rm m02 main02.o
	rm m03 main03.o
	rm m04 main04.o
	rm m05 main05.o
	rm m06 main06.o
	rm FinalBoss FinalBoss.o
