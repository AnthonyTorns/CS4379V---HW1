// DO NOT EDIT THIS FILE
#pragma once

#include <sstream>
#include <string>

#include "Node.h"

// Header implementation because of template
// Container can be things like std::vector, std::list
template <typename Container>
std::string containerToString(Container& container, std::string sep = ",") {
  std::ostringstream out;
  bool first = true;
  for (auto elem : container) {
    if (first) {
      out << "{" << elem;
      first = false;
    } else {
      out << sep << elem;
    }
  }
  out << "}";
  return out.str();
}

// Construct a linked list from an integer where each node stores a digit of the
// number; return a pointer to the head of the list, which represents the
// LOWEST digit. Assume num >= 0.
//
// E.g.,
//   makeList(123) => head -> [3 -> 2 -> 1]
//   makeList(40) => head -> [0 -> 4]
Node<int>* makeList(int num);

// Deallocate the associated memory of all the nodes in a linked list.
void freeList(Node<int>* head);

template <typename T>
std::string listToString(Node<T>* head, std::string sep = " -> ") {
  if (head == nullptr) {
    return "[]";
  }
  std::ostringstream out;
  out << "[" << head->value;
  head = head->next;
  while (head != nullptr) {
    out << sep << head->value;
    head = head->next;
  }
  out << "]";
  return out.str();
}