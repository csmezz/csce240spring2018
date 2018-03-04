#include "array.h"
/*******************************************************************************
* Copyright (c) Judson James 02.24.2018
* Used for Optional SI Assignment 01 - Single Dimension Pointers
*******************************************************************************/
// We're not allowing for undefined pointers here. We want a definite size
// for the array, so there is not a default constructor, only a
Array::Array(int size) {
  this->size_ = size;
  this->array_ = new int[size];

  for (int i = 0; i < this->GetSize(); ++i) {
    *(array_ + i) = 0;
  }
}
Array::Array(int size, int seed) {
  srand(seed);
  this->size_ = size;
	this->array_ = new int[size];

  for (int i = 0; i < this->GetSize(); ++i) {
    *(array_ + i) = rand() % 100;
  }
}
// You should delete anything in this class, but how do you fill it in?
Array::~Array() {
  delete[] this->array_;
}

/*******************************************************************************
* Accessors and Mutators
*******************************************************************************/
int Array::GetSize() {
  return this->size_;
}


/*******************************************************************************
* Public Functions
*******************************************************************************/
int Array::At(int& index) {
  assert(index < this->GetSize());
  return *(this->array_ + index);
}

void Array::At(int& index, int& value) {
  assert(index < this->GetSize());
  *(this->array_ + index) = value;
}

Array Array::AddArray(Array& other_array) {
  // Assert the size of the arrays to be equal
  assert(this->GetSize() == other_array.GetSize());
  int sum_at_i = 0;

  // Initialize return_array with the correct size
  Array return_array = Array(GetSize());

  for (int i = 0; i < this->GetSize(); ++i) {
    sum_at_i = this->At(i) + other_array.At(i);
    return_array.At(i, sum_at_i);
  }

  return return_array;
}

Array Array::MulArray(Array& other_array) {
  assert(this->GetSize() == other_array.GetSize());

  int product_at_i = 0;
  Array return_array = Array(this->GetSize());

  for (int i = 0; i < this->GetSize(); ++i) {
    product_at_i = this->At(i) + other_array.At(i);
    return_array.At(i, product_at_i);
  }

  return return_array;
}

Array Array::MulArray(int& scalar) {
	int new_value = 0;
  Array return_array = Array(this->GetSize());

  for (int i = 0; i < this->GetSize(); ++i) {
		new_value = this->At(i)*scalar;
    return_array.At(i, new_value);
  }

	return return_array;
}

string Array::ToString() {
  string return_string = "";

  for (int i = 0; i < this->GetSize(); ++i) {
    return_string += (to_string(this->At(i)) + " ");
  }

  return return_string;
}

Array operator+(Array& lhs, Array& rhs) {
  return lhs.AddArray(rhs);
}

Array operator*(Array& lhs, int rhs) {
  return  lhs.MulArray(rhs);
}

Array operator*(int lhs, Array& rhs) {
  return rhs.MulArray(rhs);
}

Array operator*(Array& lhs, Array& rhs) {
  return lhs.MulArray(rhs);
}

ostream& operator<<(ostream& lhs, Array& rhs) {
  return lhs << rhs.ToString();
}

