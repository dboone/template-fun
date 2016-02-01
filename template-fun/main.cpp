#include <iostream>
#include <fstream>
#include "Copy.h"
#include "Factorial.h"
#include "Fibonacci.h"
#include "StreamTee.h"
#include "FizzBuzz.h"
#include "TmpBookChapter2.h"

void testTmpChapter2() {
    test_add_const_ref<double> d;
    test_add_const_ref<int> i;
}

void testFizzBuzz() {
    std::cout << FizzBuzz<0>::value << std::endl;
    std::cout << FizzBuzz<1>::value << std::endl;
    std::cout << FizzBuzz<2>::value << std::endl;
    std::cout << FizzBuzz<3>::value << std::endl;
    std::cout << FizzBuzz<4>::value << std::endl;
    std::cout << FizzBuzz<5>::value << std::endl;
    std::cout << FizzBuzz<6>::value << std::endl;
    std::cout << FizzBuzz<15>::value << std::endl;
    std::cout << FizzBuzz<28>::value << std::endl;
    std::cout << FizzBuzz<30>::value << std::endl;
}

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

    testFizzBuzz();

	return 0;
}