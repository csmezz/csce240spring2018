#ifndef judsonj_array_h_
#define judsonj_array_h_

#include <cmath>
#include <assert.h>
#include <string>
using std::string;
using std::to_string;
using std::ostream;

class Array {
public:
  // Anything used to construct and destruct the class
  Array(int);
	Array(int, int);
  virtual ~Array();

  // Accessors, we're not worried about Mutators... Yet.
  int GetSize();

  // General Functions
  int At(int&);
  void At(int&, int&);
  Array AddArray(Array&);
  Array MulArray(Array&);
  Array MulArray(int&);
  string ToString();

  // Operator Functions to make Life "Easier"
  friend Array operator+(Array&, Array&);
  friend Array operator*(Array&, int);
  friend Array operator*(int, Array&);
  friend Array operator*(Array&, Array&);
  friend ostream& operator<<(ostream&, Array&);

private:
  int * array_;
  int size_;
};
#endif
