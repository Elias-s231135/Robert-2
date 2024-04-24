#include <iostream>;
#include <cstdint>

using namespace std;

struct colour {
	unsigned int colour;
}
;

//unsigned char is a 1 byte number that stores a value from 0 to 255, perfect for colours!
unsigned char GetRed() const {
	return colour >> 24;
}