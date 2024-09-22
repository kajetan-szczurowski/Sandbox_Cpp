#include <iostream>

namespace VariadicWriter {
	template <typename T>
	const void print(T argument) {
		std::cout << argument << ", ";
	}

	template <typename T, typename... Types>
	const void print(T firstValue, Types... otherValues) {
		print(firstValue);
		print(otherValues...);
	}

	static const void print() {
		std::cout << "\n";
	}
}


void work11() {
	VariadicWriter::print(5,6,7,8,1);
	VariadicWriter::print();
	VariadicWriter::print("Hej", 2, 8, 3.17);
}