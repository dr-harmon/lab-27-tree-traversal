#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "tree.h"
#include "document.h"
#include "corporation.h"
#include "expression.h"

using namespace std;

TEST_CASE("Preorder traversal")
{
	auto document = makeDocumentTree();
    vector<string> result;
	traversePreorder<string>(document, [&result](const string& s) {
		result.push_back(s);
	});
    REQUIRE(result == vector<string>{
        "Paper",
        "Title",
        "Abstract",
        "§ 1",
        "§ 1.1",
        "§ 1.2",
        "§ 2",
        "§ 2.1",
        "§ 2.2",
        "§ 2.3",
        "§ 3",
        "§ 3.1",
        "§ 3.2",
        "References"}
    );
}

TEST_CASE("Postorder traversal")
{
	auto corporation = makeCorporationTree();
    vector<string> result;
	traversePostorder<string>(corporation, [&result](const string& s) {
		result.push_back(s);
	});
    REQUIRE(result == vector<string>{
        "R&D",
        "Domestic",
        "Canada",
        "S. America",
        "Africa",
        "Europe",
        "Asia",
        "Australia",
        "Overseas",
        "International",
        "Sales",
        "Purchasing",
        "TV",
        "CD",
        "Tuner",
        "Manufacturing",
        "Electronics 'R' Us"
        }
    );
}

TEST_CASE("Inorder traversal")
{
	auto expression = makeExpressionTree();
    string result;
	traverseInorder<shared_ptr<Term>>(expression,
        [&result]() {
            result += "(";
        },
        [&result](const shared_ptr<Term>& term) {
		    result += term->toString();
	    },
        [&result]() {
            result += ")";
        }
    );
    REQUIRE(result == "((((3+1)*3)/((9-5)+2))-((3*(7-4))+6))");
}
