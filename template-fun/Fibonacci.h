#pragma once

namespace dboone {
	template <size_t n>
	struct fib;

	// explicit specialization
	template<>
	struct fib<0> {
		constexpr static auto value = 1;
	};

	// explicit specialization
	template<>
	struct fib<1> {
		constexpr static auto value = 1;
	};

	// partial specialization
	template<size_t n>
	struct fib {
		constexpr static auto value
			= fib<n - 1>::value
			+ fib<n - 2>::value;
	};
}