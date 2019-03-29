output: main.o SK6812.o Globals.o walker.o
	avr-gcc -mmcu=atmega328p main.o SK6812.o Globals.o walker.o -O3 -o output

main.o: main.cpp SK6812.h Globals.cpp Globals.h
	avr-gcc -mmcu=atmega328p main.cpp -O3 -c

SK6812.o: SK6812.cpp SK6812.h Globals.cpp Globals.h
	avr-gcc -mmcu=atmega328p SK6812.cpp -O3 -c

Globals.o: Globals.cpp Globals.h 
	avr-gcc -mmcu=atmega328p Globals.cpp -O3 -c

walker.o: walker.cpp walker.h
	avr-gcc -mmcu=atmega328p walker.cpp -O3 -c

clean:
	rm -f main.o SK6812.o walker.o Globals.o output

install: output
	avrdude -c arduino -p atmega328p -U flash:w:output -P /dev/ttyUSB0 -v -C //etc/avrdude.conf -b57600	
