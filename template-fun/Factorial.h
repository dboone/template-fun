#pragma once

namespace dboone {
	template <size_t n>
	struct fact;

	// explicit specialization
	template<>
	struct fact<0> {
		constexpr static auto value = 1;
	};

	// partial specialization
	template<size_t n>
	struct fact {
		constexpr static auto value = n * fact<n - 1>::value;
	};
}