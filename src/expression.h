#pragma once

#include "tree.h"
#include <memory>
#include <string>

class Term {
public:
    virtual std::string toString() const = 0;
    virtual ~Term() = default;
};

class Number : public Term {
    int value;
public:
    Number(int _value);
    int getValue() const;
    std::string toString() const;
};

class Variable : public Term {
    std::string name;
public:
    Variable(std::string _name);
    std::string getName() const;
    std::string toString() const;
};

class Operator : public Term {
};

class AddOperator : public Operator {
public:
    std::string toString() const;
};

class SubtractOperator : public Operator {
public:
    std::string toString() const;
};

class MultiplyOperator : public Operator {
public:
    std::string toString() const;
};

class DivideOperator : public Operator {
public:
    std::string toString() const;
};

// Generates a tree like Figure 7.11 in the textbook.
Tree<std::shared_ptr<Term>> makeExpressionTree();
