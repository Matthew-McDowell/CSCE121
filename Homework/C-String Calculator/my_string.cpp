// my_string.cpp
#include <iostream>
#include "my_string.h"
#include "my_sstream.h"

// TODO(student): define all necessary my_string methods
// NOTE: some methods suggested here may not be required for you.
//       if you don't need a method, then you are not required to implement it
// NOTE: some methods not suggested here may be required for you.
//       if you need a method, then you are required to implement it (or re-engineer your solution to no longer need the method).

// my_string methods

// constructors
//   default (done for you.  you're welcome.)
my_string::my_string() : _data(new char[1]{0}), _capacity(1), _size(0) {}
//   rule of "3"
//     my_string copy constructor
//     my_string copy assignment
//     destructor
//   c-string copy constructor

// element access
//   at
//   front
//   operator[]

// capacity
//   empty
//   size

// operations
//   concatenation
//     my_string + my_string (non-member, friend)
//     my_string + c-string (non-member, friend)
//     my_string + char (non-member, friend)
//     c-string + my_string (non-member, friend)
//     char + my_string (non-member, friend)
//     my_string += my_string
//     my_string += c-string
//     my_string += char

// search
//   find

// non-member functions
//   relational operators
//     my_string == my_string
//     my_string == c-string
//   stream operators
//     ostream instertion operator
//     istream extraction operator
//     getline
//   numeric conversions
//     to_string


// my_istringstream methods

my_istringstream::my_istringstream(const my_string& str) : _str(str), idx(0), state_fail(false), state_eof(str.empty()) {}

void my_istringstream::eat_whitespaces() {
    while (idx < _str.size() && isspace(_str[idx])) {
        idx++;
    }
}

my_istringstream& my_istringstream::operator>>(my_string& str) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    my_string s;
    while (idx < _str.size() && !isspace(_str[idx])) {
        s += _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    str = s;
    return *this;
}

my_istringstream& my_istringstream::operator>>(char& c) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    if (idx < _str.size()) {
        c = _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    return *this;
}

bool my_istringstream::good() const { return !(state_fail || state_eof); }
bool my_istringstream::fail() const { return state_fail; }
bool my_istringstream::eof() const { return state_eof; }

// TODO(student): define other my_istringstream methods, if any
