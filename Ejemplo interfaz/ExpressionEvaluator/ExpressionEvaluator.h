#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H
/*
#include <cctype>
#include <iostream>

#include "Stack.h"

/// Evaluates an arithmetic expression where tokens are separated by space.
/// Uses a simplification of Dijkstra's Shunting-yard algorithm
/// https://en.wikipedia.org/wiki/Shunting-yard_algorithm
/// Code adapted from http://www.geeksforgeeks.org/expression-evaluation/
template <typename DataType>
class ExpressionEvaluator
{
  private:
	// Stack for numbers: 'values'
	Stack<DataType> values;
	// Stack for Operators: 'ops'
	Stack<char> ops;

	// Default: constructor, (1) copy constructor, (2) move constructor, (3) destructor,
	// (4) copy assignment operator and (5) move assignment oeprator are fine for this class
	// template, because these default implementations will call their respective methods in Stack.
	// The Stack template manages the dynamic memory. ExpresionEvaluator does not manage dynamic
	// memory. We do not want to delete the default implementations, because they allows users of
	// this class template to make copies, for example, allocating them in containers.

  public:
	/// Reads an expression reading it from the given stream and returns the result
	DataType evaluate(std::istream& in)
	{
		while ( true )
		{
			// If current token is a number, push it to stack for numbers
			DataType value;
			in >> std::ws;
			if ( isdigit(in.peek()) && in >> value )
				values.push( value );
			else
			{
				// It should be an operator
				char op = 0;
				if ( ! (in >> op) )
					break;

				switch ( op )
				{
					// Current token is an opening brace, push it to 'ops'
					case '(':
						ops.push(op);
						break;

					// Closing brace encountered, solve entire brace
					case ')':
						while (ops.top() != '(')
							applyOperator();
						ops.pop();
						break;

					// Current token is an operator.
					case '+': case '-': case '*': case '/':
						// While top of 'ops' has same or greater precedence to current
						// token, which is an operator. Apply operator on top of 'ops'
						// to top two elements in values stack
						while ( ops.empty() == false && hasPrecedence(op, ops.top()) )
							applyOperator();

						// Push current token to 'ops'.
						ops.push(op);
						break;
				}
			}
		}

		// Entire expression has been parsed at this point, apply remaining
		// ops to remaining values
		while ( ops.empty() == false )
			applyOperator();

		// Top of 'values' contains result, return it
		return values.pop();
	}

	// Returns true if 'op2' has higher or same precedence as 'op1',
	// otherwise returns false.
	bool hasPrecedence(char op1, char op2)
	{
		if (op2 == '(' || op2 == ')') return false;
		if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) return false;
		return true;
	}

	void applyOperator()
	{
		DataType b = values.pop();
		DataType a = values.pop();
		values.push( applyOperator(ops.pop(), a, b) );
	}

	// A utility method to apply an operator 'op' on operands 'a'
	// and 'b'. Return the result.
	static DataType applyOperator(char op, const DataType& a, const DataType& b)
	{
		switch (op)
		{
			case '+': return a + b;
			case '-': return a - b;
			case '*': return a * b;
			case '/': return a / b;
		}
		return DataType();
	}
};
*/
#endif // EXPRESSIONEVALUATOR_H
