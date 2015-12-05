#pragma once
#include <iostream>
#include <string>

namespace dboone {
	// function template used to 
	// provide a value to a function
	template <size_t count>
	void copy(const std::string& str) {
		for (auto i = 0; i < count; ++i) {
			std::cout << str << std::endl;
		}
	}
}