/*
 *  gVector3.h
 */
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */
#include <iomanip>		//need this for shorter numbers
#include <iostream>
using namespace std;

#ifndef GVECTOR3_H
#define GVECTOR3_H

#define EPSILON 0.00001
#define M_PI 3.14159

class gVector3{
private:
	float data[3];
public:
	///----------------------------------------------------------------------
	/// Constructors
	///----------------------------------------------------------------------
	gVector3();
	gVector3(float x, float y, float z);
	
	///----------------------------------------------------------------------
	/// Getters/Setters
	///----------------------------------------------------------------------		
	/// Returns the value at index
	float operator[](unsigned int index) const;
	
	/// Returns a reference to the value at index
	float& operator[](unsigned int index);

	/// Prints the vector to standard output in a nice format
	void print() const;
	
	///----------------------------------------------------------------------
	/// Vector Operations
	///----------------------------------------------------------------------
	/// Returns the geometric length of the vector
	float length() const;
		
	///----------------------------------------------------------------------
	/// Friend Functions
	///----------------------------------------------------------------------		
	/// Checks if v1 == v2
	friend bool operator==(const gVector3& v1, const gVector3& v2);
	
	/// Checks if v1 != v2
	friend bool operator!=(const gVector3& v1, const gVector3& v2);
	
	/// Vector Addition (v1 + v2)
	friend gVector3 operator+ (const gVector3& v1, const gVector3& v2);
	
	/// Vector Subtraction (v1 - v2)
	friend gVector3 operator- (const gVector3& v1, const gVector3& v2);
	
	/// Scalar Multiplication (v * c)
	friend gVector3 operator* (const gVector3& v, float c);	
	
	/// Scalar Multiplication (c * v)
	friend gVector3 operator* (float c, const gVector3& v);
	
	/// Scalar Division (v/c)
	friend gVector3 operator/ (const gVector3& v, float c);
	
	/// Dot Product (v1 * v2)
	friend float operator* (const gVector3& v1, const gVector3& v2);
	
	/// Cross Product (v1 % v2)
	friend gVector3 operator% (const gVector3& v1, const gVector3& v2);
};

#endif