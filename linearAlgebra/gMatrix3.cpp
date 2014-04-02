#include "gMatrix3.h"

///----------------------------------------------------------------------
/// Constructors
///----------------------------------------------------------------------
/// Default Constructor.  Initialize to matrix of all 0s.
gMatrix3::gMatrix3()
{
	data[0] = gVector3(); data[1] = gVector3(); data[2] = gVector3();
}

/// Initializes matrix with each vector representing a row in the matrix
gMatrix3::gMatrix3(const gVector3& row1, const gVector3& row2, const gVector3& row3)
{
	data[0] = row1; data[1] = row2; data[2] = row3;
}

///----------------------------------------------------------------------
/// Getters
///----------------------------------------------------------------------	
/// Returns the values of the row at the index
gVector3 gMatrix3::operator[](unsigned int index) const
{
	assert(index >= 0 && index <= 3);
	return data[index];
}

/// Returns a reference to the row at the index
gVector3& gMatrix3::operator[](unsigned int index)
{
	assert(index >= 0 && index <= 3);
	return data[index];
}

/// Returns a column of the matrix
gVector3 gMatrix3::getColumn(unsigned int index) const
{
	return gVector3(data[0][index],data[1][index],data[2][index]);
}

/// Prints the matrix to standard output in a nice format
void gMatrix3::print() const
{
	cout.precision(2);
	cout << "[ " << endl;
	cout << "\t"; data[0].print();
	cout << "\t"; data[1].print();
	cout << "\t"; data[2].print();
	cout << "]" << endl;
}

///----------------------------------------------------------------------
/// Matrix Operations
///----------------------------------------------------------------------	
/// Returns the transpose of the matrix (v_ij == v_ji)
gMatrix3 gMatrix3::transpose() const
{
	return gMatrix3(getColumn(0), getColumn(1), getColumn(2));
}

///----------------------------------------------------------------------
/// Static Initializers
///----------------------------------------------------------------------	
/// Creates a 3-D rotation matrix.
/// Takes an angle in degrees and outputs a 3x3 rotation matrix
gMatrix3 gMatrix3::rotation2D(float angle)
{
	//change angle degrees to radians
	//(degrees * PI) / 180
	float radians = (angle * M_PI) / 180;
	return gMatrix3( gVector3(cos(radians), -sin(radians), 0),
					 gVector3(sin(radians),  cos(radians), 0),
					 gVector3(			 0,             0, 1) 
				   );
}

/// Takes an x and y displacement and outputs a 3x3 translation matrix
gMatrix3 gMatrix3::translation2D(float x, float y)
{
	return gMatrix3( gVector3(1, 0, x), 
					 gVector3(0, 1, y),
					 gVector3(0, 0, 1));
}

/// Takes an x and y scale and outputs a 3x3 scale matrix
gMatrix3 gMatrix3::scale2D(float x, float y)
{
	return gMatrix3(gVector3(x, 0, 0),
					gVector3(0, y, 0),
					gVector3(0, 0, 1));
}

/// Generates a 3x3 identity matrix
gMatrix3 gMatrix3::identity()
{
	return gMatrix3(gVector3(1, 0, 0),
					gVector3(0, 1, 0),
					gVector3(0, 0, 1));
}

///----------------------------------------------------------------------
/// Friend Functions
///----------------------------------------------------------------------
/// Checks if m1 == m2
bool     operator==(const gMatrix3& m1, const gMatrix3& m2)
{
	if (m1[0] == m2[0]){
		if (m1[1] == m2[1]){
			if (m1[2] == m2[2]){
				return true;
			}
		}
	}
	else return false;
}

/// Checks if m1 != m2
bool     operator!=(const gMatrix3& m1, const gMatrix3& m2)
{
	if (m1[0] != m2[0]){
		if (m1[1] != m2[1]){
			if (m1[2] != m2[2]){
				return true;
			}
		}
	}
	else return false;
}

/// Matrix addition (m1 + m2)
gMatrix3 operator+ (const gMatrix3& m1, const gMatrix3& m2)
{
	return gMatrix3(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2]);
}

/// Matrix subtraction (m1 - m2)
gMatrix3 operator- (const gMatrix3& m1, const gMatrix3& m2)
{
	return gMatrix3(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2]);
}

/// Scalar multiplication (m * c)
gMatrix3 operator* (const gMatrix3& m, float c)
{
	return gMatrix3(m[0] * c, m[1] * c, m[2] * c);
}

/// Scalar multiplication (c * m)
gMatrix3 operator* (float c, const gMatrix3& m)
{
	return gMatrix3(c * m[0], c * m[1], c * m[2]);
}

/// Scalar division (m / c)
gMatrix3 operator/ (const gMatrix3& m, float c)
{
	return gMatrix3(m[0] / c, m[1] / c, m[2] / c);
}

/// Matrix multiplication (m1 * m2)
gMatrix3 operator* (const gMatrix3& m1, const gMatrix3& m2)
{
	return gMatrix3(
	gVector3(m1[0] * m2.getColumn(0), m1[0] * m2.getColumn(1), m1[0] * m2.getColumn(2)),
	gVector3(m1[1] * m2.getColumn(0), m1[1] * m2.getColumn(1), m1[1] * m2.getColumn(2)),
	gVector3(m1[2] * m2.getColumn(0), m1[2] * m2.getColumn(1), m1[2] * m2.getColumn(2))
	);//redo this with matrix * vector operator
}

/// Matrix/vector multiplication (m * v)
/// Assume v is a column vector (ie. a 3x1 matrix)
gVector3 operator* (const gMatrix3& m, const gVector3& v)
{
	return gVector3(m[0] * v, m[1] * v, m[2] * v);
}

/// Vector/matrix multiplication (v * m)
/// Assume v is a row vector (ie. a 1x3 matrix)
gVector3 operator* (const gVector3& v, const gMatrix3& m)
{
	return gVector3(v * m[0], v * m[1], v * m[2]);
}