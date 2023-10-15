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
void traversePreorder(Node<E>& node, std::function<void(const E&)> visit)
{
    visit(node.e);
    for (auto& node : node.children) {
        traversePreorder(node, visit);
    }
}

template <typename E>
void traversePreorder(Tree<E>& tree, std::function<void(const E&)> visit)
{
    traversePreorder(tree.root, visit);
}

template <typename E>
void traversePostorder(const Node<E>& node, std::function<void(const E&)> visit)
{
    for (auto& node : node.children) {
        traversePostorder(node, visit);
    }
    visit(node.e);
}

template <typename E>
void traversePostorder(const Tree<E>& tree, std::function<void(const E&)> visit)
{
    traversePostorder(tree.root, visit);
}

template <typename E>
void traverseInorder(const Node<E>& node,
    std::function<void(void)> beginTraversal,
    std::function<void(const E&)> visit,
    std::function<void(void)> endTraversal)
{
    bool isInternal = !node.children.empty();
    if (isInternal) {
        beginTraversal();
        traverseInorder(node.children[0], beginTraversal, visit, endTraversal);
    }
    visit(node.e);
    if (isInternal) {
        traverseInorder(node.children[1], beginTraversal, visit, endTraversal);
        endTraversal();
    }
}

template <typename E>
void traverseInorder(const Tree<E>& tree,
    std::function<void(void)> beginTraveral,
    std::function<void(const E&)> visit,
    std::function<void(void)> endTraversal)
{
    traverseInorder(tree.root, beginTraveral, visit, endTraversal);
}
