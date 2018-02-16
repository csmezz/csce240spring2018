#include "main.h"
/******************************************************************************
* Copyright (c) Judson James, 02.14.2018
* CSCE 240 Homework 02 Tester for Supplemental Instruction Purposes
******************************************************************************/
void TestAddition(void);
void TestMultiplication(void);
void TestToString(void);
void TestToComplex(void);

int main(int argc, char** argv) {
  TestAddition();
  TestMultiplication();
  TestToString();
  TestToComplex();
}

void TestAddition() {
  Complex complex_one = Complex(1.0, 2.1);
  Complex complex_two = Complex(2.1, 7.9);
  int additive_int = 7;
  double additive_double = 13.1;
  int passes = 0;
  int fails = 0;

  cout << "Testing Addition:" << endl;

  Complex test_one = complex_one + additive_int;
  if (test_one.real() == 8) {
    ++passes;
  } else {
    cout << "\tFailed Addition Case One" << endl;
    cout << "\tExpected 8\tRecieved: " << test_one.real() << endl;
    ++fails;
  }

  Complex test_two = complex_one + additive_double;
  if (test_two.real() == 14.1) {
    ++passes;
  } else {
    cout << "\tFailed Addition Case Two" << endl;
    cout << "\tExpected 14.1\tRecieved: " << test_two.real() << endl;
    ++fails;
  }

  Complex test_three = complex_one + complex_two;
  if (test_three.real() == 3.1 && test_three.imag() == 10.0) {
    ++passes;
  } else {
    cout << "\tFailed Addition Case Three" << endl;
    cout << "\tExpected 3.1 & 10.0\tRecieved: " << test_three.real() << "\t" << test_three.imag() << endl;
    ++fails;
  }

  Complex test_four = additive_int + complex_two;
  if (test_four.real() == 9.1) {
    ++passes;
  } else {
    cout << "\tFailed Addition Case Four" << endl;
    cout << "\tExpected 9.1\tRecieved: " << test_four.real() << endl;
    ++fails;
  }

  Complex test_five = additive_double + complex_two;
  if (test_five.real() == 15.2) {
    ++passes;
  } else {
    cout << "\tFailed Addition Case Five" << endl;
    cout << "\tExpected 15.2\tRecieved: " << test_five.real() << endl;
    ++fails;
  }

  cout << "\tPassed: " << passes << " out of " << (passes+fails) << endl;
}

void TestMultiplication() {
  Complex complex_one = Complex(1.0, 2.1);
  Complex complex_two = Complex(2.1, 7.9);
  int multiplier_int = 7;
  double multiplier_double = 13.1;
  int passes = 0;
  int fails = 0;

  cout << "Testing Multiplication:" << endl;

  Complex test_one = complex_one * multiplier_int;
  if (test_one.real() == 7.0 && test_one.imag() == 14.7) {
    ++passes;
  } else {
    cout << "\tFailed Multiplication Case One" << endl;
    cout << "\tExpected 7.0 & 14.7\tRecieved: " << test_one.real() <<
          " & " << test_one.imag() << endl;
    ++fails;
  }

  Complex test_two = complex_one * multiplier_double;
  if (test_two.real() == 13.1 && test_two.imag() == 27.51) {
    ++passes;
  } else {
    cout << "\tFailed Multiplication Case Two" << endl;
    cout << "\tExpected 13.1 & 27.51\tRecieved: " << test_two.real() <<
          " & " << test_two.imag() << endl;
    ++fails;
  }

  Complex test_three = complex_one * complex_two;
  if (test_three.real() == -14.49 && test_three.imag() == 12.31) {
    ++passes;
  } else {
    cout << "\tFailed Multiplication Case Three" << endl;
    cout << "\tExpected -14.49 & 12.31\tRecieved: " << test_three.real() << "\t" << test_three.imag() << endl;
    ++fails;
  }

  Complex test_four = multiplier_int * complex_two;
  if (test_four.real() == 14.7 && test_four.imag() == 55.3) {
    ++passes;
  } else {
    cout << "\tFailed Multiplication Case Four" << endl;
    cout << "\tExpected 14.7 & 55.3\tRecieved: " << test_four.real() <<
          " & " << test_four.imag() << endl;
    ++fails;
  }

  Complex test_five = multiplier_double * complex_two;
  if (test_five.real() == 27.51 && test_five.imag() == 103.49) {
    ++passes;
  } else {
    cout << "\tFailed Multiplication Case Five" << endl;
    cout << "\tExpected 27.51 & 103.49\tRecieved: " << test_five.real() <<
          " & " << test_five.imag() << endl;
    ++fails;
  }

  cout << "\tPassed: " << passes << " out of " << (passes+fails) << endl;
}

void TestToString() {
  string test_string = "2 + 2i";
  Complex test_one = Complex(2.0, 2.0);
  Complex test_two = Complex(2.5, 1.71);
  Complex test_three = Complex(0.0, 2.0);
  Complex test_four = Complex(2.0, 0.0);
  Complex test_five = Complex(2.0, -2.0);
  int passes = 0;
  int fails = 0;

  cout << "Testing ToString:" << endl;

  // Test One - Base Case
  if (test_one.ToString() == test_string) {
    ++passes;
  } else {
    cout << "\tFailed ToString Case One" << endl;
    cout << "\tExpected " << test_string << "\tRecieved: " <<
            test_one << endl;
    ++fails;
  }

  test_string = "2.5 + 1.71i";
  if (test_two.ToString() == test_string) {
    ++passes;
  } else {
    cout << "\tFailed ToString Case Two" << endl;
    cout << "\tExpected " << test_string << "\tRecieved: " <<
            test_two << endl;
    ++fails;
  }
  test_string = "2i";
  if (test_three.ToString() == test_string) {
    ++passes;
  } else {
    cout << "\tFailed ToString Case Three" << endl;
    cout << "\tExpected " << test_string << "\tRecieved: " <<
            test_three << endl;
    ++fails;
  }

  test_string = "2";
  if (test_four.ToString() == test_string) {
    ++passes;
  } else {
    cout << "\tFailed ToString Case Four" << endl;
    cout << "\tExpected " << test_string << "\tRecieved: " <<
            test_four << endl;
    ++fails;
  }

  test_string = "2 - 2i";
  if (test_five.ToString() == test_string) {
    ++passes;
  } else {
    cout << "\tFailed ToString Case Five" << endl;
    cout << "\tExpected " << test_string << "\tRecieved: " <<
            test_five << endl;
    ++fails;
  }

  cout << "\tPassed " << passes << " out of " << (passes + fails) << endl;
}

void TestToComplex() {
  int passes = 0;
  int fails = 0;
  string test_one = "2 + 2i";
  string test_two = "2.5 + 2.5i";
  string test_three = "2";
  string test_four = "2i";
  string test_five = "2 - 2i";

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
    cout << "\tExpected: " << test_one << "\tRecieved: " << complex_one;
    ++fails;
  }

  if (complex_two.real() == 2.5 && complex_two.imag() == 2.5) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Two" << endl;
    cout << "\tExpected: " << test_two << "\tRecieved: " << complex_two;
    ++fails;
  }

  if (complex_three.real() == 2.0 && complex_three.imag() == 0.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Three" << endl;
    cout << "\tExpected: " << test_three << "\tRecieved: " << complex_three;
    ++fails;
  }

  if (complex_four.real() == 0.0 && complex_four.imag() == 2.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Four" << endl;
    cout << "\tExpected: " << test_four << "\tRecieved: " << complex_four;
    ++fails;
  }

  if (complex_five.real() == 2.0 && complex_five.imag() == -2.0) {
    ++passes;
  } else {
    cout << "\tFailed ToComplex Case Five" << endl;
    cout << "\tExpected: " << test_five << "\tRecieved: " << complex_five;
    ++fails;
  }
}
