/***************************************************************
  Student Name: Vansh Sharma
  File Name: Tester.hpp
  Assignment number: 1

 Declares functions used to test legal and illegal userid/passwords.
 ***************************************************************/
#ifndef TESTER_HPP
#define TESTER_HPP

#include "HashTable.hpp"
#include <string>

// Runs legal userid/password tests
void runLegalTests(HashTable& table);

// Runs illegal userid/password tests
void runIllegalTests(HashTable& table);

#endif
