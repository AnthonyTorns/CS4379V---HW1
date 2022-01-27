# HW1: Coding / C++ Practice

This is the very first homework in CS 4379V. The goal is to explore your knowledge in programming and C++. This assignment is due on Thursday, January 27, 2021 at 11:59pm.

## Submitting & Grading
In order to submit this assignment, you must download your code as a ZIP file and upload it to Gradescope.

We've provided some example inputs and outputs to help you test your code and check your work in `main.cpp`. The autograder in general may have other test cases beyond what is provided here. You should consider writing your own examples.

Your grade on this homework will be a combination of the below (with relative breakdown on Gradescope):
- **Q0 Initial Logistics (2 points):** See below.
- **Q1 LeetCode (2 points):** See below.
- **Autograder test cases (26 points):** These results can be seen after submitting to Gradescope. You have unlimited tries to submit.
- **Documentation (8 points):** Your explanations for your approach to each question in the comments.
- **Code Style (4 points):** We recommended referencing the [CS 106B style guide](https://web.stanford.edu/class/cs106b/resources/style_guide.html) and slides from class (on Canvas). You do not need to follow it exactly. As long as your code style is consistent and reasonable, you will get this credit.

You can consult outside resources and work with other students as long as you write up your own solutions and cite any links or people you received help from within citations.txt.

### Corrections
*If you miss points on this assignment,* there will be an opportunity to earn half of them back by doing homework corrections, so don't worry so much about the grade if you're having a tough time on some of the questions. More information will be posted on Piazza.

## Getting Help
If you have any trouble with any aspects of the homework, please first check Piazza to see if anyone else has had a similar issue. The "hw1" tag on the top will show only posts relevant to HW1.

You can also attend any of the office hours (details on Piazza).

## Q0. Initial logistics
If you haven't already, please complete all tasks in [this Piazza note](https://piazza.com/class/kyi5za6v5tz4lf?cid=7).

## Q1. LeetCode: Fizz Buzz
Although many of the homework questions already have coding questions / interview-style content, to ensure consistent practice,
we may include curated LeetCode questions that progress throughout the semester. You may do these questions in any LeetCode supported language
(ideally the language you would use during an interview or if a company gave you a coding assessment).

Nearly all solutions for LeetCode questions are available online through the platform or elsewhere, so it will have to be the honor code that you give an honest attempt
yourself first. I am okay if you give your best effort, then explore other solutions online to understand better afterward, but your final submission should be **fully written, character-by-character, by you, and you should be able to fully explain and reproduce what you did to me in an interview-style setting.** You should also add what you referenced in citations.txt. This bar holds for all homework, but just a reminder that it applies for LeetCode as well. This is how you will get the most out of this coding practice (no solutions on the job, after all!).

If you are new to LeetCode or struggle with these kinds of questions for now, you may find this difficult at first (looking up a lot of syntax, and hitting "Run" several times before getting a correct answer). That is okay!

If you find the questions I provide more straightforward, I challenge you to write the code without looking up any syntax, inspect your code carefully to find any bugs (without ever running it) and trying to get it to work completely correctly on the first or second run - it's harder than you think! That behavior prepares you best for the interview.

**Instructions**
- Solve [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- After clicking "Submit" and getting status "Accepted", take a screenshot of the entire window (with the time submitted and your code).
- Attach the **complete and successful screenshot** as an image named `Q1.jpg` in your code submissions.



## Q2. findMissingNumber
Convert the following pseudocode algorithm into C++. You'll find example tests within the main method to ensure you're headed in the right direction. Make sure you understand each example.
```
algorithm findMissingNumber
  Input: integer vector vec of length-n where each element is distinct
    and in the range [0, n]
  Output: integer x where x is in the range [0, n], but not in V

  s = the sum of all numbers in vec
  return (n(n+1))/2 - s
```
Write your answer in `HW1.cpp`.

## Q3. findMaxOfVector
Write `findMaxOfVector`, which takes in a vector of integers and returns the largest
integer within the vector. If the vector is empty, throw an
`std::invalid_argument`. Some examples:

```
std::cout << findMaxOfVector({1, 3, 4, 5, 2}) << std::endl;  // should output 5
std::cout << findMaxOfVector({-1, -3, -4, -5, -2}) << std::endl;  // should output -1
std::cout << findMaxOfVector({}) << std::endl;  // should throw
```
Write your answer in `HW1.cpp`.

## Q4. findTwoSumPair
Write `findTwoSumPair`, which takes in a vector of integers and a target sum, and
returns a pair that represents two *distinct* **indices** of elements that sum up to the target value (with indexes sorted). There are no explicit time complexity constraints here (i.e. algorithm just needs to work as intended). Also make sure to handle empty input. Some examples:
```
std::cout << "Q3" << std::endl;
std::vector<int> q3Input1{0, 2, 3, 4, 5};
std::pair<int, int> q3Out1 = findTwoSumPair(q3Input1, 6);
std::pair<int, int> q3Out2 = findTwoSumPair(q3Input1, 10);

std::cout << q3Out1.first << " " << q3Out1.second << std::endl;  // should output 1 3
std::cout << q3Out2.first << " " << q3Out2.second << std::endl;  // should output -1 -1
```
* In the first example, `vec[1] + vec[3] = 2 + 4 = 6`.
* In the second example, we returned `-1, -1` because there are not two
distinct elements within the vector that sum to 10 (you can't use 5 twice).
Write your answer in `HW1.cpp`.

Hint: to return a pair, you can use std::make_pair(1, 2).

## Q5. add

Write `add`, which given two numbers represented as linked lists of single-digit
integers, returns their sum as a linked list of integers. Return the head node.

The linked list is represented as follows:
```
template <typename T>
struct Node {
  T value_;
  Node<T>* next_ = nullptr;
};
```
Your implementation should operate digit-by-digit with a carry such that you can add together numbers that would normally result in overflow.

We have provided a util function `makeList` to convert an integer to its corresponding list representation. For conveniences, the list stores the digits from the lowest to the highest, e.g., `makeList(123) => head -> [3 -> 2 -> 1]`.

Some examples for `add`:
```
Node<int>* q4bInput1 = makeList(123);  // [3 -> 2 -> 1] 
Node<int>* q4bInput2 = makeList(242);  // [2 -> 4 -> 2]
Node<int>* q4bOut1 = add(q4bInput1, q4bInput2);
std::cout << listToString(q4bOut1)
        << std::endl;  // should output [5 -> 6 -> 3] (meaning 365)
freeList(q4bInput1);
freeList(q4bInput2);
freeList(q4bOut1);

Node<int>* q4bInput3 = makeList(999);
Node<int>* q4bInput4 = makeList(1);
Node<int>* q4bOut2 = add(q4bInput3, q4bInput4);
std::cout << listToString(q4bOut2)
        << std::endl;  // should output [0 -> 0 -> 0 -> 1] (meaning 1000)
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
```
Write your answer in `HW1.cpp` (note that we have provided some starter code already).

Refresher on pointers, memory allocation, and deallocation for your reference:
* To create a `Node` object, use `Node<int>* ptr = new Node<int>()`. `new` dynamically allocates memory for this.
* We provided a `freeList` function that will traverse the linked list and free every node. `freeList` is all we need here, but always remember when you have allocated memory (i.e. typed `new`) to free it when finished (i.e. `delete ptr`).
* To check whether there are "memory leaks" (i.e., allocated memory but not deallocated), you can run valgrind on repl.it with `valgrind --leak-check=full ./main`

Please note that this question is at the upper-end of the C++ intricacies we will lean on in the course. Having familiarity with pointers here will serve us well later on (e.g. with trees).

Hint: to get started with this question, think about how you added numbers back in the day when first learning about addition (digit-by-digit, starting from the ones place, and keeping track of a carry).
