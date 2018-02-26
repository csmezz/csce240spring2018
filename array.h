#ifndef judsonj_array_h_
#define judsonj_array_h_
/*******************************************************************************
* Copyright (c) Judson James 02.24.2018
* For use with Supplemental Instruction OSA 1, Spring 2018
*******************************************************************************/
#include <cmath>
#include <assert.h>
#include <string>
using std::string;
using std::to_string;
using std::ostream;

class Array {
public:
  Array(int size);
	Array(int size, int seed);
  virtual ~Array();

  int GetSize();

  int At(int& index);
  void At(int& index, int& assigned_value);
  Array AddArray(Array& additive);
  Array MulArray(Array& multiplier);
  Array MulArray(int& scalar);
  string ToString();

  friend Array operator+(Array& lhs, Array& rhs);
  friend Array operator*(Array& lhs, int rhs);
  friend Array operator*(int lhs, Array& rhs);
  friend Array operator*(Array& lhs, Array& rhs);
  friend ostream& operator<<(ostream& lhs, Array& rhs);

private:
  int * array_;
  int size_;
};
#endif
