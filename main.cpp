#include <iostream>
#include <vector>

#include "HW1.h"
#include "util.h"

int main() {

  std::cout << "Q1" << std::endl;
  std::cout << findMissingNumber({0, 1, 2, 4, 5}) << std::endl;  // should output 3
  std::cout << findMissingNumber({5, 0, 4, 3, 1}) << std::endl;  // should output 2
  std::cout << findMissingNumber({}) << std::endl;  // should output 0
  std::cout << findMissingNumber({9, 3, 5, 1, 4, 8, 2, 10, 0, 6}) << std::endl;  // should output 7

  std::cout << "Q2" << std::endl;
  std::cout << findMaxOfVector({1, 3, 4, 5, 2}) << std::endl;  // should output 5
  std::cout << findMaxOfVector({-1, -3, -4, -5, -2}) << std::endl;  // should output -1
  bool emptyCaseCorrect = false;
  try {
    std::cout << findMaxOfVector({}) << std::endl;  // should throw
  } catch (const std::invalid_argument& ia) {
    emptyCaseCorrect = true;
  }
  if (emptyCaseCorrect) {
    std::cout << "findMaxOfVector appears correct for the empty case." << std::endl;
  } else {
    std::cout << "findMaxOfVector appears incorrect for the empty case."
              << std::endl;
  }

  std::cout << "Q3" << std::endl;
  std::vector<int> q3Input1{0, 2, 3, 4, 5};
  std::pair<int, int> q3Out1 = findTwoSumPair(q3Input1, 6);
  std::pair<int, int> q3Out2 = findTwoSumPair(q3Input1, 10);

  std::cout << q3Out1.first << " " << q3Out1.second
            << std::endl;  // should output 1 3
  std::cout << q3Out2.first << " " << q3Out2.second
            << std::endl;  // should output -1 -1

  std::cout << "Q4" << std::endl;
  Node<int>* q4bInput1 = makeList(123);
  Node<int>* q4bInput2 = makeList(242);
  Node<int>* q4bOut1 = add(q4bInput1, q4bInput2);
  std::cout << listToString(q4bOut1)
            << std::endl;  // should output [5 -> 6 -> 3]
  freeList(q4bInput1);
  freeList(q4bInput2);
  freeList(q4bOut1);

  Node<int>* q4bInput3 = makeList(999);
  Node<int>* q4bInput4 = makeList(1);
  Node<int>* q4bOut2 = add(q4bInput3, q4bInput4);
  std::cout << listToString(q4bOut2)
            << std::endl;  // should output [0 -> 0 -> 0 -> 1]
  freeList(q4bInput3);
  freeList(q4bInput4);
  freeList(q4bOut2);

  Node<int>* q4bInput5 = makeList(2147483647);
  Node<int>* q4bInput6 = makeList(12345);
  Node<int>* q4bOut3 = add(q4bInput5, q4bInput6); // normally would overflow
  std::cout << listToString(q4bOut3) << std::endl;
  // should output [2 -> 9 -> 9 -> 5 -> 9 -> 4 -> 7 -> 4 -> 1 -> 2]
  freeList(q4bInput5);
  freeList(q4bInput6);
  freeList(q4bOut3);

}
