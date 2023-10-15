#include "expression.h"

using namespace std;

Number::Number(int _value) : value(_value)
{}

int Number::getValue() const
{
    return value;
}

string Number::toString() const
{
    return to_string(getValue());
}

Variable::Variable(string _name) : name(_name)
{}

string Variable::getName() const
{
    return name;
}

string Variable::toString() const
{
    return getName();
}

string AddOperator::toString() const
{
    return "+";
}

string SubtractOperator::toString() const
{
    return "-";
}

string MultiplyOperator::toString() const
{
    return "*";
}

string DivideOperator::toString() const
{
    return "/";
}

Tree<shared_ptr<Term>> makeExpressionTree()
{
    return {
        {make_shared<SubtractOperator>(), {
            {make_shared<DivideOperator>(), {
                {make_shared<MultiplyOperator>(), {
                    {make_shared<AddOperator>(), {
                        {make_shared<Number>(3)},
                        {make_shared<Number>(1)},
                    }},
                    {make_shared<Number>(3)},
                }},
                {make_shared<AddOperator>(), {
                    {make_shared<SubtractOperator>(), {
                        {make_shared<Number>(9)},
                        {make_shared<Number>(5)},
                    }},
                    {make_shared<Number>(2)},
                }},
            }},
            {make_shared<AddOperator>(), {
                {make_shared<MultiplyOperator>(), {
                    {make_shared<Number>(3)},
                    {make_shared<SubtractOperator>(), {
                        {make_shared<Number>(7)},
                        {make_shared<Number>(4)},
                    }},
                }},
               {make_shared<Number>(6)},
            }},
        }}
    };
}
