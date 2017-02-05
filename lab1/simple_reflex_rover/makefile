default: reflex_rover

reflex_rover: reflex_rover.o
	g++ -o simple_reflex_rover reflex_rover.o 
reflex_rover.o: reflex_rover.cc
	g++ -c reflex_rover.cc
clean: 
	rm -f *.o
	rm simple_reflex_rover
