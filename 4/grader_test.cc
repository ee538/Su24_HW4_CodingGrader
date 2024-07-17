#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"

// Helper function to check tree structure
bool compareTrees(TreeNode *a, TreeNode *b)
{
  if (a == nullptr && b == nullptr)
    return true;
  if (a == nullptr || b == nullptr)
    return false;
  return (a->val == b->val) && compareTrees(a->left, b->left) &&
         compareTrees(a->right, b->right);
}

// Test case for createTree with a simple tree
TEST(CreateTreeTest, SimpleTree)
{
  std::vector<int> values = {1, 2, 3, -1, 4};
  TreeNode *expected = new TreeNode(1);
  expected->left = new TreeNode(2);
  expected->right = new TreeNode(3);
  expected->left->right = new TreeNode(4);

  TreeNode *result = createTree(values);
  EXPECT_EQ(compareTrees(expected, result), 1);
}

// Test case for createTree with all nodes
TEST(CreateTreeTest, CompleteTree)
{
  std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *expected = new TreeNode(1);
  expected->left = new TreeNode(2);
  expected->right = new TreeNode(3);
  expected->left->left = new TreeNode(4);
  expected->left->right = new TreeNode(5);
  expected->right->left = new TreeNode(6);
  expected->right->right = new TreeNode(7);

  TreeNode *result = createTree(values);
  EXPECT_EQ(compareTrees(expected, result), 1);
}

// Test case for createTree with missing nodes
TEST(CreateTreeTest, TreeWithNulls)
{
  std::vector<int> values = {1, -1, 2, -1, -1, 3};
  TreeNode *expected = new TreeNode(1);
  expected->right = new TreeNode(2);
  expected->right->left = new TreeNode(3);

  TreeNode *result = createTree(values);
  EXPECT_EQ(compareTrees(expected, result), 1);
}

// Test case for createTree with an empty tree
TEST(CreateTreeTest, EmptyTree)
{
  std::vector<int> values = {};
  TreeNode *result = createTree(values);
  EXPECT_EQ(result, nullptr);
}

// Test case for inorder traversal
TEST(TreeTraversalTest, InorderTraversal)
{
  std::vector<int> values = {1, 2, 3, -1, 4, 5, 6};
  TreeNode *root = createTree(values);

  std::vector<int> expected = {2, 4, 1, 5, 3, 6};
  std::vector<int> result = inorderTraversal(root);

  EXPECT_EQ(result, expected);
}

// Test case for preorder traversal
TEST(TreeTraversalTest, PreorderTraversal)
{
  std::vector<int> values = {1, 2, 3, -1, 4, 5, 6};
  TreeNode *root = createTree(values);

  std::vector<int> expected = {1, 2, 4, 3, 5, 6};
  std::vector<int> result = preorderTraversal(root);

  EXPECT_EQ(result, expected);
}

// Test case for postorder traversal
TEST(TreeTraversalTest, PostorderTraversal)
{
  std::vector<int> values = {1, 2, 3, -1, 4, 5, 6};
  TreeNode *root = createTree(values);

  std::vector<int> expected = {4, 2, 5, 6, 3, 1};
  std::vector<int> result = postorderTraversal(root);

  EXPECT_EQ(result, expected);
}
