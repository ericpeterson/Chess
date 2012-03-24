#include <iostream>

#include "King.h"

using namespace std;

/**
 *  Determines if the tests are successful based on current test result
 *
 *  @param IN `result` The current test result
 *  @param OUT `success` The success of the test. False if `result` is false;
 *    otherwise it will keep its most recent value.
 */
inline void evaluateSuccess (bool result, bool & success) {
  if (false == result) {
    success = false;
  }
}


int main (int argc, char* argv[]) {
  bool success = true;
  bool testResult = true;

  testResult = King::Test(cout);
  evaluateSuccess(testResult, success);

  if (success) {
    cout << "All tests passed!" << endl;
  } else {
    cout << "Fail!" << endl;
  }

  return 0;
}
