# Lab 27: Tree Traversal

In this lab, we'll explore the different ways of traversing a tree:

* preorder
* postorder
* inorder

To keep things simple, all code in this lab will be based on the `Tree` type defined in `tree.h`. Unlike the full-featured tree ADT as described in the textbook, it has no methods and is split across two structures:

1. `struct Tree` contains the root node of a tree.
2. `struct Node` contains the data at a given node and a vector of its children.

Also provided are some utility functions to generate example trees based on the textbook's examples:

* `makeDocumentTree`: Returns a tree like Figure 7.6.
* `makeCorporationTree`: Returns a tree like Figure 7.2.
* `makeExpressionTree`: Returns a tree like Figure 7.11.

Function prototypes for the preorder, postorder, and inorder traversals are in `tree.h`. They take a tree and a lambda as parameters. The lambda performs the "visit" operation on each node as the tree is traversed. Refer to the unit tests in `tree_test.cpp` for examples of how to invoke the traversal functions with an appropriate lamba.

The implementation for these functions is missing. Your task is to provide them and make all unit tests pass.

## Part 1: Preorder

Fill in the `traversePreorder` function so that it performs a preorder walk of the given tree, as defined in Fragment 7.9 in the textbook:

    Algorithm preorder(T, p):
        perform the "visit" action for node p
        for each child q of p do
            recursively traverse the subtree rooted at q by calling preorder(T,q)

The "visit" action should simply invoke the lambda. (Hint: Add a helper function that takes a node instead of a tree as the parameter, then invoke it from the original `traversePreorder`.)

To test your implementation, use the `makeDocumentTree` helper function. For example, in `main` you could add the following:

    auto document = makeDocumentTree();
    traversePreorder<string>(document, [](const string& s) {
        cout << s << endl;
    });

This should print:

    Paper
    Title
    Abstract
    § 1
    § 1.1
    § 1.2
    § 2
    § 2.1
    § 2.2
    § 2.3
    § 3
    § 3.1
    § 3.2
    References

Note that the preorder is the same as if the document were prepared for printing.

## Part 2: Postorder

Next, fill in the `traversePreorder` function so that it performs a postorder walk of the given tree, as defined in Fragment 7.12 in the textbook:

    Algorithm postorder(T, p):
        for each child q of p do
            recursively traverse the subtree rooted at q by calling postorder(T,q)
        perform the "visit" action for node p

Use the `makeCorporationTree` helper to print the elements of Figure 7.2 in the textbook in postorder fashion. Make sure the order matches your understanding of postorder.

In this case, the postorder is not very useful. We will examine practical applications of postorder in subsequent labs.

## Part 3: Inorder

Finally, fill in the `traverseInorder` function so that it performs an inorder walk of the given tree, as defined in Fragment 7.27 in the textbook:

    Algorithm inorder(T, p):
        if p is an internal node then
            inorder(T, p.left())        {recursively traverse left subtree}
        perform the "visit" action for node p
        if p is an internal node then
            inorder(T, p.right())       {recursively traverse right subtree}

Inorder walks only make sense if each node has at most 2 children, which are normally defined as a "left" and a "right" child. We will take a closer look at such trees in subsequent labs, but for now, for the inorder walk let's assume that:

* All nodes have either 0 or 2 children.
* If a node has 2 children, `children[0]` is the left one and `children[1]` is the right one.

The tree in Figure 7.11 in the textbook has these properties, so we can use the `makeExpressionTree` helper for testing inorder traversal. Print all elements on the same line, separated by spaces. (Do not print `endl`.) Use `term->toString()` to obtain a string representation a `shared_ptr<Term>` object. You should then see:

    3 + 1 * 3 / 9 - 5 + 2 - 3 * 7 - 4 + 6

Note this the equivalent infix expression of the tree is:

    ((((3+1)*3)/((9-5)+2))-((3*(7-4))+6))

Except for the parentheses, this is identical to the inorder walk. We can add the parentheses by observing that:

* An open parenthesis occurs during the left child's traversal.
* A close parenthesis occurs during the right child's traversal.

Therefore, we can modify the algorithm as follows:

    Algorithm inorder(T, p):
        if p is an internal node then
            perform the "beginTraversal" action for node p
            inorder(T, p.left())        {recursively traverse left subtree}
        perform the "visit" action for node p
        if p is an internal node then
            perform the "endTraversal" action for node p
            inorder(T, p.right())       {recursively traverse right subtree}

Implement `traverseInorder` invoke these actions, and the visit action, at the appropriate times. You can then test the code by defining a `beginTraversal` lambda that prints `(` and an `endTraversal` lambda that prints ')'. The output should match the infix expression syntax shown above.

At this point, all unit tests should pass.
