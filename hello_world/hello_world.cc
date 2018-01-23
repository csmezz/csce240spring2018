/*******************************************************************************
* Author and Copyright: Judson James
* For: CSCE 240, Spring 2018
*******************************************************************************/

// These are the includes and the namespace usage for "cout", which is our
// "print"  function for C++. You can alternatively use "using namespace std;"
// to replace both lines 12 and 13, however, the way I'm using it here is more
// verbose and explicit.
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

// This is a basic example of a main method, where the parameters are the
// number of arguments provided at the command line along with the names of the
// arguments provided.
int main (int argc, char** argv) {
  cout << "Hello World" << endl;

  // This is an exit code for the main function, this can be useful depending on
  // how the 
  return 0;
}
