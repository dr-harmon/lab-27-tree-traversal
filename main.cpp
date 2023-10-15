#include "tree.h"
#include "document.h"
#include "corporation.h"
#include "expression.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	auto document = makeDocumentTree();
	traversePreorder<string>(document, [](const string& s) {
		cout << s << endl;
	});

	auto corporation = makeCorporationTree();
	traversePostorder<string>(corporation, [](const string& s) {
		cout << s << endl;
	});

	auto expression = makeExpressionTree();
	traverseInorder<shared_ptr<Term>>(expression,
		[]() {
			cout << "(";
		},
		[](const shared_ptr<Term>& term) {
			cout << term->toString() << " ";
		},
		[]() {
			cout << ")";
		}
	);

	return EXIT_SUCCESS;
}
