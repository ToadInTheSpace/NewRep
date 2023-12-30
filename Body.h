#ifndef BITARRAY_H
#define BITARRAY_H

#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <gtest/gtest.h>
#include <array>

class BitArray
{
	//Tests
	FRIEND_TEST(BitArray, EmptyCreate);
	FRIEND_TEST(BitArray, Create);
	FRIEND_TEST(BitArray, CopyCreate);
	FRIEND_TEST(BitArray, SetOne);
	FRIEND_TEST(BitArray, SetAll);
	FRIEND_TEST(BitArray, ResetOne);
	FRIEND_TEST(BitArray, ResetAll);
	FRIEND_TEST(BitArray, any);
	FRIEND_TEST(BitArray, none);
	FRIEND_TEST(BitArray, empty);
	FRIEND_TEST(BitArray, size);
	FRIEND_TEST(BitArray, count);
	FRIEND_TEST(BitArray, swap);
	FRIEND_TEST(BitArray, resize);
	FRIEND_TEST(BitArray, push_back);
	FRIEND_TEST(BitArray, to_string);
	FRIEND_TEST(BitArray, OperatorElement);
	FRIEND_TEST(BitArray, OperatorEqually);
	FRIEND_TEST(BitArray, OperatorAnd);
	FRIEND_TEST(BitArray, OperatorNotEqually);
	FRIEND_TEST(BitArray, OperatorOr);
	FRIEND_TEST(BitArray, OperatorInversion);
	FRIEND_TEST(BitArray, OperatorLShift);
	FRIEND_TEST(BitArray, OperatorRShift);
	FRIEND_TEST(BitArray, OperatorLShiftConst);
	FRIEND_TEST(BitArray, OperatorRShiftConst);
	FRIEND_TEST(BitArray, clear);

public:
	//Default constructor. Creates an empty class. Fills length value with 0, and bits with value NULL
	BitArray();
	//Copy constructor
	BitArray(const BitArray&);
	//Constructs BitArray, that contains given num of bits. 
	//If first variable less then 0, bit array will be maden such as BitArray()
	//If second varianle less then zero or more then square of first variable array will be maiden fool of false
	explicit BitArray(int, unsigned long = 0);
	//Destructor
	~BitArray();

	//Sets bit with given index to value
	//If  first variable not included in the array value this function will not work
	//if second value is empty functuon will make it true 
	BitArray& set(int , bool = true);
	//sets whole array to 1
	BitArray& set();
	//sets array with given index to 0
	BitArray& reset(int);
	//sets whole array to 0
	//If  first variable not included in the array value this function will not work
	BitArray& reset();
	//clears array
	void clear();

	//Returns true if array contains any 1 bit
	bool any() const;
	//Returns true if there is no any 1 bit
	bool none() const;
	//Returns true if length of array is 0
	bool empty() const;
	//Returns length of array
	int size() const;
	//Return amount of 1 bits
	int count() const;

	//Swapping values of two BitArrays
	void swap(BitArray&, BitArray&);
	//Changes size of BitArray. 
	//In case of extension, new elements will be initialized as int value
	void resize(int, bool);
	//Adds new bit in the end of BitArray
	void push_back(bool bit);

	//Returns string format of array
	std::string to_string() const;



	//Performs a bitwise shift to the left in a given variable
	BitArray& operator<<=(int);
	//Performs a bitwise shift to the right in a given variable
	BitArray& operator>>=(int);
	//returns a variable with a bitwise shift to the left
	BitArray operator<<(int) const;
	//returns a variable with a bitwise shift to the right
	BitArray operator>>(int) const;

	//returns i bit
	//if variable not included in the array function will return false
	bool operator[](int i) const;

	//Performs a bit inversion operation and returns a BitArray with it
	BitArray operator~() const;

	//next functions writes the value to the variable from which the function was called
	//also if the array lengths are not equal, next functiona will not work
	
	//makes all bits inperforms the == operation with each bit of the array in pairs
	BitArray& operator=(const BitArray&);
	//makes all bits inperforms the && operation with each bit of the array in pairs
	BitArray& operator&=(const BitArray&);
	//makes all bits inperforms the || operation with each bit of the array in pairs
	BitArray& operator|=(const BitArray&);
	//makes all bits inperforms the != operation with each bit of the array in pairs
	BitArray& operator^=(const BitArray&);
private:
	bool* bits;
	int len;
};

//returns true if arrays are equal and false if not
bool operator==(const BitArray&, const BitArray&);
//returns false if arrays are equal and true if not
bool operator!=(const BitArray&, const BitArray&);

//the following functions return a BitArray with the && operation performed on the specified variables
//Performs the operation &&
BitArray operator&(const BitArray&, const BitArray&);
//Performs the operation ||
BitArray operator|(const BitArray&, const BitArray&);
//Performs the operation !=
BitArray operator^(const BitArray&, const BitArray&);



#endif