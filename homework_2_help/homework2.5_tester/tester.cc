#include "tester.h"
/*******************************************************************************
* Copyright (c) Judson James 02.28.2018
* Made for Supplemental Instruction for CSCE 240, Spring 2018
*******************************************************************************/
void TestLessThan();
void TestIsComplex();
void TestToComplex();
void TestOperator();

int main(int argc, char** argv) {
  TestLessThan();
  TestIsComplex();
  TestToComplex();
  TestOperator();
}

//******************************************************************************
// Test Cases
// 1) Complex < Complex
// 2) Complex < int
// 3) Complex < double
// 4) int < Complex
// 5) double < Complex
//
// Remember: you're comparing the modulo of the complexes, not the values.
// You can't compare an imaginary number with a real number (the formula you
// need is in the powerpoint)
//
// Just a tip: if you're going to have a test for booleans, explicitly say what
// the returned boolean should return. This is just for sanity's sake.
void TestLessThan() {
  Complex complex_one = Complex(1.0, 3.4);
  Complex complex_two = Complex(43.0, 17.1);
  int int_comp = 1;
  double double_comp = 1.0;
  int passes = 0;
  int fails = 0;

  cout << "Testing Less Than Method" << endl;
  if ((complex_one < complex_two) == true) {
    ++passes;
  } else {
    cout << "\tFailed Case One: Complex < Complex" << endl;
    ++fails;
  }
  if ((complex_one < double_comp) == false) {
    ++passes;
  } else {
    cout << "\tFailed Case Two: Complex < double" << endl;
    ++fails;
  }
  if ((complex_one < int_comp) == false) {
    ++passes;
  } else {
    cout << "\tFailed Case Three: Complex < int" << endl;
    ++fails;
  }
  if ((double_comp < complex_two) == true) {
    ++passes;
  } else {
    cout << "\tFailed Case Four: double < Complex" << endl;
    ++fails;
  }
  if ((int_comp < complex_two) == true) {
    ++passes;
  } else {
    cout << "\tFailed Case Five: int < Complex" << endl;
    ++fails;
  }

  cout << "\tTotal: " + passes + " passes of " + (passes+fails) << endl;
}

//******************************************************************************
// If you're having issues with this function, keep in mind that the Method call
// is static. Also, a good thing to use for this function is the "putback"
// in the istream object. The easiest way to parse the string is probably
// using c_str and manipulating the char* can check for your cases. Make sure it
// isn't anything other than numbers, 'i', '(' or ')' and '+' or '-'. Keep in
// mind that characters are primitive types and can be compared
// lexicographically.
// You can add to this function, I just wanted a base out there for people to
// use.
void TestIsComplex() {
  string test_one = "(2 + 2i)";
  string test_two = "uh oh spaghetti-o's";
  string test_three = "(3i)";
  int passes = 0;
  int fails = 0;

  cout << "Testing IsComplex" << endl;
  // IsComplex(const string&)
  if (Complex::IsComplex(test_one) == true) {
    ++passes;
  } else {
    cout << "\tFailed Test One: " << test_one << endl;
    ++fails;
  }
  if (Complex::IsComplex(test_two) == false) {
    ++passes;
  } else {
    cout << "\tFailed Test One: " << test_two << endl;
    ++fails;
  }

  // IsComplex(istream&)
  // Ref http://www.cplusplus.com/reference/istream/istream/putback/
  // This one is weird, Professor Lewis will likely cover this in class
  // Thursday just to make sure I'm not giving the wrong thing.
  // I will try and update this before Friday
}
//******************************************************************************
// Essentially copied and pasted from the last Tester
void TestToComplex() {
  int passes = 0;
  int fails = 0;
  string test_one = "(2 + 2i)";
  string test_two = "(2.5 + 2.5i)";
  string test_three = "(2)";
  string test_four = "(2i)";
  string test_five = "(2 - 2i)";

  // Additional Hint: You can call the >> operator with cin instead,
  // and then type in the actual string you want to pass into ToComplex.
  // *cough cough*
  Complex complex_one = Complex::ToComplex(test_one);
  Complex complex_two = Complex::ToComplex(test_two);
  Complex complex_three = Complex::ToComplex(test_three);
  Complex complex_four = Complex::ToComplex(test_four);
  Complex complex_five = Complex::ToComplex(test_five);

  if (complex_one.real() == 2.0 && complex_one.imag() == 2.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case One" << endl;
    cout << "\tExpected: " << test_one << "\tRecieved: " <<
        complex_one << endl;
    ++fails;
  }

  if (complex_two.real() == 2.5 && complex_two.imag() == 2.5) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Two" << endl;
    cout << "\tExpected: " << test_two << "\tRecieved: " <<
        complex_two << endl;
    ++fails;
  }

  if (complex_three.real() == 2.0 && complex_three.imag() == 0.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Three" << endl;
    cout << "\tExpected: " << test_three << "\tRecieved: " <<
        complex_three << endl;
    ++fails;
  }

  if (complex_four.real() == 0.0 && complex_four.imag() == 2.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Four" << endl;
    cout << "\tExpected: " << test_four << "\tRecieved: " <<
        complex_four << endl;
    ++fails;
  }

  if (complex_five.real() == 2.0 && complex_five.imag() == -2.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Five" << endl;
    cout << "\tExpected: " << test_five << "\tRecieved: " <<
        complex_five << endl;
    ++fails;
  }

  cout << "\tPassed " << passes << " out of " << (passes+fails) << endl;
}

//******************************************************************************
// This should Essentially work the same way as the last function
// Yes, I'm aware that this requires you to actually input a string
// No, I didn't want to redirect where the stream buffer was going
void TestOperator() {
  Complex test_complex;
  cout << "Testing Operator" << endl;
  cout << "\tPlease enter an appropriate string for ToComplex"
  cin >> test_complex;

  // The operator should check for the validity of the string. If it was not
  // valid, then the assert() function should have dumped the core and wouldn't
  // have gotten here anyway.
  // Ref: http://www.cplusplus.com/reference/cassert/assert/
  cout << "\tTest Operator was a success" << endl;
}
