#include <iostream>
#include <fstream>
#include "Copy.h"
#include "Factorial.h"
#include "Fibonacci.h"
#include "StreamTee.h"

int main(int argc, char* argv) {
	using dboone::copy;
	using dboone::fact;
	using dboone::fib;
	using dboone::streamTee;

	copy<3>("Hello, world!");

	std::cout << fact<5>::value << std::endl;
	std::cout << fib<5>::value << std::endl;

	std::ofstream out("test.log");
	streamTee("Hello, world!", std::cout, out);
	streamTee(std::endl, std::cout, out);

	return 0;
}