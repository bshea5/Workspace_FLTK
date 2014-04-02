///* Brandon Shea
//   CS351 Prof. Allbeck
//   02/06/13
//
//main.cpp is testing linear algebra library
////commented out in order to test scene graph
//Backup is in BackupFiles folder further up in the directory
//   */
//
//#include <iostream>
//#include "gMatrix3.h"
//
//void main(void)
//{
//	using namespace std;
//	cout << "Hello World" << endl;
//	cout << "Welcome to Linear Algebra library testing (^_^)" << endl;
//	cout << "Author: Brandon Shea\n CS351\n 02/06/13 " << endl;
//	//----- TEST VECTORS -----
//	cout << "\nTESTING VECTORS" << endl;
//	gVector3 answer_vector = gVector3(5, 7, 9);
//	gVector3 vector_one = gVector3(1, 2, 3);
//	gVector3 vector_two = gVector3(4, 5, 6);
//	vector_one.print();
//	cout << "vector_one length:\t" << vector_one.length() << endl;
//	vector_two.print();
//
//	gVector3 vector_three = vector_one + vector_two;
//	cout << "\nAnswer: ";
//	vector_three.print();
//	cout << "Expected value: ";
//	answer_vector.print();
//
//	vector_three = vector_three - vector_two;
//	cout << "\nAnswer: ";
//	vector_three.print();
//	cout << "Expected value: ";
//	vector_one.print();
//
//	cout << "\n";
//	vector_three = vector_three * 3;
//	vector_three.print();
//	vector_three = 3 * vector_three;
//	vector_three.print();
//	vector_three = vector_three / 3;
//	vector_three.print();
//	gVector3 vector_four = vector_one % vector_two;
//	vector_four.print();
//	//---- TEST MATRICES ----
//	cout << "\nTESTING MATRIX FRIEND FUNCTIONS" << endl;
//	gMatrix3 matrix_one = gMatrix3(vector_one, vector_two, vector_three);
//	matrix_one.print();
//	gMatrix3 matrix_two = matrix_one.transpose();
//	matrix_two.print();
//	gMatrix3 matrix_three = matrix_one + matrix_two;
//	matrix_three.print();
//	matrix_three = matrix_three - matrix_two - matrix_two;
//	matrix_three.print();
//	matrix_three = 2 * matrix_three;
//	matrix_three.print();
//	matrix_three = matrix_three / 2;
//	matrix_three.print();
//	matrix_three = matrix_one * matrix_two;
//	matrix_three.print();
//	vector_four = matrix_one * matrix_two.getColumn(0);
//	vector_four.print();
//	cout << "again" << endl;
//	vector_four = matrix_two.getColumn(0) * matrix_one;
//	vector_four.print();
//	//---- MATRIX OPERATIONS ----
//	gMatrix3 rotation_matrix = gMatrix3::rotation2D(90);
//	gMatrix3 scale_matrix = gMatrix3::scale2D(1, 2);
//	gMatrix3 translation_matrix = gMatrix3::translation2D(2, 2);
//	cout << "\nRotation Matrix:" << endl;
//	rotation_matrix.print();
//	cout << "\nScale Matrix" << endl;
//	scale_matrix.print();
//	cout << "\nTranslation Matrix:" << endl;
//	translation_matrix.print();
//	//---- TEST VECTOR EQUIVALENCE ----
//	cout << "\n---- Testing Equivalence ----" << endl;
//	gVector3 vector_five = gVector3(5, 4, 3);
//	gVector3 vector_six = gVector3(5, 4, 3);
//	cout << "\t";
//	vector_five.print();
//	if (vector_five == vector_six)
//		cout << "\t\tEquals" << endl;
//	else
//		cout << "\t\tNot Equals" << endl;
//	cout << "\t";
//	vector_six.print();
//	//---- TEST MATRIX EQUIVALENCE ----
//	gMatrix3 matrix_four = matrix_one;
//	cout << "\n\n\n";
//	matrix_one.print();
//	if (matrix_one == matrix_four)
//		cout << "\t\tEquals" << endl;
//	else
//		cout << "\t\tNot Equals" << endl;
//	matrix_four.print();
//
//	cout << "\n\n\n";
//	matrix_one.print();
//	if (matrix_one == matrix_two)
//		cout << "\t\tEquals" << endl;
//	else
//		cout << "\t\tNot Equals" << endl;
//	matrix_two.print();
//
//
//	system("PAUSE");
//}
//
