#pragma once
#include <ostream>

namespace dboone {
	using CoutType = std::basic_ostream<char, std::char_traits<char> >;
	using StandardEndLine = CoutType&(CoutType&);
	using StandardEndLinePtr = StandardEndLine*;

	void streamTee(StandardEndLinePtr) {}

	template <typename TStreamHead, typename... TStreamTail>
	void streamTee(StandardEndLinePtr manip, TStreamHead& head, TStreamTail&... tail) {
		manip(head);
		streamTee(manip, tail...);
	}

	template <typename TOutput>
	void streamTee(const TOutput&) {}

	template <typename TOutput, typename TStreamHead, typename... TStreamTail>
	void streamTee(const TOutput& output, TStreamHead& head, TStreamTail&... tail) {
		head << output;
		streamTee(output, tail...);
	}
}