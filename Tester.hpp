#ifndef TESTER_HPP
#define TESTER_HPP

#include "HashTable.hpp"
#include <string>

// Runs legal userid/password tests
void runLegalTests(HashTable& table);

// Runs illegal userid/password tests
void runIllegalTests(HashTable& table);

#endif
