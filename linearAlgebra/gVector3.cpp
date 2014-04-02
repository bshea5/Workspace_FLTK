#include "gVector3.h"

///----------------------------------------------------------------------
/// Constructors
///----------------------------------------------------------------------
gVector3::gVector3()
{
	data[0] = 0; data[1] = 0; data[2] = 0;
}

gVector3::gVector3(float x, float y, float z)
{
	data[0] = x; data[1] = y; data[2] = z;
}

///----------------------------------------------------------------------
/// Getters/Setters
///----------------------------------------------------------------------		
/// Returns the value at index
float gVector3::operator[](unsigned int index) const
{
	assert(index >= 0 && index <= 3);
	return data[index];
}

/// Returns a reference to the value at index
float& gVector3::operator[](unsigned int index)
{
	assert(index >= 0 && index <= 3);
	return data[index];
}

/// Prints the vector to standard output in a nice format
void gVector3::print() const
{
	//print as column
//	cout << "[" << data[0] << endl;
//	cout << " " << data[1] << endl;
//	cout << " " << data[2] << "]" << endl;
	//print as row
	cout.precision(2);
	cout << setiosflags(ios::fixed);
	cout << "[" << data[0]
		 << ", " << data[1]
		 << ", " << data[2] << "]" << endl;
}

///----------------------------------------------------------------------
/// Vector Operations
///----------------------------------------------------------------------
/// Returns the geometric length of the vector
float gVector3::length() const
{
	return sqrtf((data[0] * data[0]) + (data[1] * data[1]));
}

///----------------------------------------------------------------------
/// Friend Functions
///----------------------------------------------------------------------		
/// Checks if v1 == v2
bool operator==(const gVector3& v1, const gVector3& v2)
{
	if (abs(v1[0]) - abs(v2[0]) < EPSILON){
		if (abs(v1[1]) - abs(v2[1]) < EPSILON){
			if (abs(v1[2]) - abs(v2[2]) < EPSILON){
				return true;
			}
		}
	}
	else return false;
}

/// Checks if v1 != v2
bool operator!=(const gVector3& v1, const gVector3& v2)
{
	if (abs(v1[0]) - abs(v2[0]) > EPSILON){
		if (abs(v1[1]) - abs(v2[1]) > EPSILON){
			if (abs(v1[2]) - abs(v2[2]) > EPSILON){
				return true;
			}
		}
	}
	else return false;
}

/// Vector Addition (v1 + v2)
gVector3 operator+ (const gVector3& v1, const gVector3& v2)
{
	return gVector3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

/// Vector Subtraction (v1 - v2)
gVector3 operator- (const gVector3& v1, const gVector3& v2)
{
	return gVector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

/// Scalar Multiplication (v * c)
gVector3 operator* (const gVector3& v, float c)
{
	return gVector3(v[0] * c, v[1] * c, v[2] * c);
}

/// Scalar Multiplication (c * v)
gVector3 operator* (float c, const gVector3& v)
{
	return gVector3(c * v[0], c * v[1], c * v[2]);
}

/// Scalar Division (v/c)
gVector3 operator/ (const gVector3& v, float c)
{
	return gVector3(v[0] / c, v[1] / c, v[2] / c);
}

/// Dot Product (v1 * v2)
float operator* (const gVector3& v1, const gVector3& v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

/// Cross Product (v1 % v2)
gVector3 operator% (const gVector3& v1, const gVector3& v2)
{
	return gVector3(+(v1[1] * v2[2] - v1[2] * v2[1]),
					-(v1[0] * v2[2] - v1[2] * v2[0]),
					+(v1[0] * v2[1] - v1[1] * v2[0]) );
}