#pragma once
#include <ostream>

namespace dboone {
	using CoutType = std::basic_ostream<char, std::char_traits<char> >;
	using StandardEndLine = CoutType&(CoutType&);
	using StandardEndLinePtr = StandardEndLine*;

	template <typename TStreamHead>
	void streamTee(StandardEndLinePtr manip, TStreamHead& head) {
		manip(head);
	}

	template <typename TStreamHead, typename... TStreamTail>
	void streamTee(StandardEndLinePtr manip, TStreamHead& head, TStreamTail&... tail) {
		manip(head);
		streamTee(manip, tail...);
	}

	template <typename TOutput, typename TStreamHead>
	void streamTee(TOutput output, TStreamHead& head) {
		head << output;
	}

	template <typename TOutput, typename TStreamHead, typename... TStreamTail>
	void streamTee(TOutput output, TStreamHead& head, TStreamTail&... tail) {
		head << output;
		streamTee(output, tail...);
	}
}