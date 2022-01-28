#include <iostream>   // std::cout, std::cin
#include <stdexcept>  // std::invalid_argument
#include <vector>     // std::vector

#include "Node.h"  // Node
#include "util.h" 
#include <numeric>
#include <limits>
#include <map>
 // containerToString, listToString, makeList, freeList
// Note: the include comments are just for your educational purposes.
// Normally, one does not include those comments. Include additional
// headers as needed.

/*
 * Add your key ideas to this comment.
 * How did you approach the problem - I figured this problem could be solved by gathering the size and sum of all numbers in the vector with thye use of library functions .size() as well as the accumulate function. 
 * Why does your code work - My code works because it effiecently catpures both size and sum value and returns a value based on the given formula. 
 * 
 */
int findMissingNumber(const std::vector<int>& vec) {
  //throw std::logic_error("not implemented");
  int n = vec.size();
  int s = accumulate(vec.begin(), vec.end(), 0);
  return (n * (n+1))/2 - s;
};

/*  
 * Add your key ideas to this comment.
 * How did you approach the problem - To begin with, I emplemented the two given cases. Which are if the vector is empty or only has one element. 
 Next I focusd on solving other cases when the size of the vector is greater than 1. 
 * Why does your code work - My solution work because it quickly return's the result for the two given cases but also iteravely find the max element of a vector. 
 *
 */
int findMaxOfVector(const std::vector<int>& vec) {
  //throw std::logic_error("not implemented");

  if (vec.size() < 1) {
    throw std::invalid_argument("Vector is Empty");
  }

  else if (vec.size() == 1) {
    return vec[0];
  }
  
  int max = std::numeric_limits<int>::min();
  
  for(int i = 0; i < vec.size(); i ++) {
    if(vec[i] > max) {
      max = vec[i]; 
    }
  }

  return max;
}

/*
 * Add your key ideas to this comment.
 * How did you approach the problem - I wanted to practice solving this algorithm as efficently as posiible. I chose to use a hash map sice the time complexity will be O(n) originally. However there was one edge case that I was unable to solve for. Will come into office hours for help.
 I ultimately solved the problem with two for loops 
 * Why does your code work? - my code iteravely searcehs each element in the vector and looks for tow entries that equal the desired sum
 *
 */
std::pair<int, int> findTwoSumPair(const std::vector<int>& vec, int targetSum) {
  //throw std::logic_error("not implemented");
  /*std::map<int, int> pairs;
  //std::cout<<targetSum<<std::endl;

  for(int i = 0; i < vec.size(); i++) {
    int complement = targetSum - vec[i] ;
    
    if(pairs.count(complement))  {
      int comp_index = std::distance(pairs.begin(), pairs.find(complement));
      return std::make_pair(comp_index, i );
    }
    
    else {
      pairs.insert(std::make_pair(vec[i], complement));
    }
  }  
  return std::make_pair(-1,-1);
  */
  for( int i = 0; i < vec.size(); i++ ) {
    for(int j = i + 1; j < vec.size(); j++) {
      if(vec[i] + vec[j] == targetSum) {
        return std::make_pair(i, j);
      }
    }
  }
  return std::make_pair(-1,-1);
}

/*
 * Add your key ideas to this comment
 * How did you approach the problem - Originally I beleived we could add each value to the place sum however I realized that we needed to check for isnstances where null nodes may occur
 * Why does your code work? - My checks if each node is null or not. It solves edge cases where the number of digits are different 
 *
 */
Node<int>* add(Node<int>* l1, Node<int>* l2) {
  Node<int>* head = nullptr;
  Node<int>* tail = nullptr;
  int carry = 0;
  while (l1 != nullptr || l2 != nullptr || carry > 0) {
    int placeSum = 0;
    placeSum = carry;
    // TODO your code here (remove logic_error)
    //throw std::logic_error("not implemented");
    if (l1) {
      placeSum += l1->value;
       l1 = l1->next;
    }
    
    if (l2) {
      placeSum += l2->value;
      l2 = l2->next;
    }
    
    carry = placeSum/10;
    placeSum %= 10;
    // construct the new node
    Node<int>* tmp = new Node<int>(); 
    tmp->value = placeSum;
    tmp->next = nullptr;
    if (head == nullptr) {
      head = tmp;
      tail = tmp;
    } else {
      tail->next = tmp;
      tail = tail->next;
    }
  }
  return head;
}