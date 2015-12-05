#include <iostream>
#include "Copy.h"
#include "Factorial.h"
#include "Fibonacci.h"

int main(int argc, char* argv) {
	using dboone::copy;
	using dboone::fact;
	using dboone::fib;

	copy<3>("Hello, world!");

	std::cout << fact<5>::value << std::endl;
	std::cout << fib<5>::value << std::endl;

	return 0;
}