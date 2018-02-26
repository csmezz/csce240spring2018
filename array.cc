#include "array.h"
/*******************************************************************************
* Copyright (c) Judson James 02.24.2018
* For use with Supplemental Instruction OSA 1, Spring 2018
*******************************************************************************/
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

Array::~Array() {
  delete[] this->array_;
}

/*******************************************************************************
* Your job from here is to get add the other functions listed within the header
* file. For information about specifics, please refer to the README.txt
*******************************************************************************/
