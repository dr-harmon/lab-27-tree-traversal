#pragma once

#include <functional>
#include <vector>

template <typename E>
struct Node {
    E e;
    std::vector<Node> children;
};

template <typename E>
struct Tree {
    Node<E> root;
};

template <typename E>
void traversePreorder(Tree<E>& tree, std::function<void(const E&)> visit)
{
    // TODO
}

template <typename E>
void traversePostorder(const Tree<E>& tree, std::function<void(const E&)> visit)
{
    // TODO
}

template <typename E>
void traverseInorder(const Tree<E>& tree,
    std::function<void(void)> beginTraveral,
    std::function<void(const E&)> visit,
    std::function<void(void)> endTraversal)
{
    // TODO
}
