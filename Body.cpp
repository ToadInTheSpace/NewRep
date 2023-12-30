#include "Body.h"



bool operator==(const BitArray& a, const BitArray& b) {
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
		if (a.operator[](i) != b.operator[](i))
			return false;
	return true;
}

bool operator!=(const BitArray& a, const BitArray& b) {
	return !(operator==(a, b));
}

BitArray operator&(const BitArray& a, const BitArray& b) {
	BitArray c(a);
	return c.operator&=(b);
}

BitArray operator|(const BitArray& a, const BitArray& b) {
	BitArray c(a);
	return c.operator|=(b);
}

BitArray operator^(const BitArray& a, const BitArray& b) {
	BitArray c(a);
	return c.operator^=(b);
}