# Variables
CC = avr-gcc
CC_FLAGS = -mmcu=atmega328p -O3

# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.d)

$(EXEC): $(OBJECTS)
	$(CC) $(CC_FLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CC_FLAGS) -MMD -MP -c $< -o $@

all: $(EXEC)

clean:
	rm -f $(OBJECTS) $(EXEC) $(DEPS)

rebuild: clean all

reinstall: clean install

install: $(EXEC)
	avrdude -c arduino -p atmega328p -U flash:w:$(EXEC) -P /dev/ttyUSB0 -v -C //etc/avrdude.conf -b57600

-include $(DEPS)
