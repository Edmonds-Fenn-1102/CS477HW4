HWFive: driver.o
	g++ -o HWFive driver.o
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm *.o HWFive