# Make file for extra credit assignment

OBJS	= main.o BattleBot.o BotSegment.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
MAIN_DEPS	= BattleBot.h BotSegment.h
BOT_DEPS = BotSegment.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o battle_sim $(OBJS)
	@echo "Done! Finished building battle bot program. Run battle_sim"
main.o:	main.cpp $(MAIN_DEPS)
	@echo "Compiling Main..."
	$(CC) $(CCFLAGS) -c main.cpp
BattleBot.o: BattleBot.cpp $(BOT_DEPS)
	@echo "Compiling BattleBot..."
	$(CC) $(CCFLAGS) -c BattleBot.cpp
BotSegment.o: BotSegment.cpp 
	@echo "Compiling BotSegments..."
	$(CC) $(CCFLAGS) -c BotSegment.cpp


# -----
# clean by removing object files and executable

clean:
	rm $(OBJS) battle_sim
