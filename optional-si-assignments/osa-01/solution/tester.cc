#include "tester.h"

int main(int argc, char** argv) {
  Array array_size_ten = Array(10);

  cout << "Printing Empty Array of size 10" << endl;
  cout << array_size_ten << endl;

  cout << "Inserting 3 at the end of the array" << endl;
	int index = array_size_ten.GetSize() - 1;
	int input_value = 3;
  array_size_ten.At(index, input_value);
  cout << array_size_ten << endl;

  cout << "Creating a randomized array of the same size" << endl;
  Array random_array_ten = Array(10, rand());
  cout << random_array_ten << endl;

  cout << "Adding two arrays" << endl;
  Array sum_of_arrays = array_size_ten + random_array_ten;
  cout << sum_of_arrays << endl;

  cout << "Multiplying two arrays" << endl;
  Array product_of_arrays = array_size_ten * random_array_ten;
  cout << product_of_arrays << endl;

  cout << "Creating an array of size 15" << endl;
  Array random_array_fifteen = Array(15, rand());
  cout << random_array_fifteen << endl;

  cout << "Comparing two arrays of different sizes (should quit)" << endl;
  Array broken_array = random_array_ten * random_array_fifteen;

  return 0;
}
