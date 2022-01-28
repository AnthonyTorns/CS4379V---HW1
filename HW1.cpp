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
 * How did you approach the problem?
 * Why does your code work?
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
 * How did you approach the problem?
 * Why does your code work?
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
 * How did you approach the problem?
 * Why does your code work?
 *
 */
std::pair<int, int> findTwoSumPair(const std::vector<int>& vec, int targetSum) {
  //throw std::logic_error("not implemented");
  std::map<int, int> pairs;
   for(int i = 0; i < vec.size(); i++) {
     std::cout<<vec[i]<<std::endl;
   }

  for(int i = 0; i < vec.size(); i++) {
    int complement = targetSum - vec[i];
    if(pairs.count(complement))  {
      int comp_index = std::distance(pairs.begin(), pairs.find(complement));
      return std::make_pair(comp_index, i );
    }
    
    else {
      pairs.insert(std::make_pair(vec[i], i));
    }
  }  
  return std::make_pair(-1,-1);
}

/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
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