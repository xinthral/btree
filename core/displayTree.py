#!/usr/bin/env python3

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_level_order(arr, root, i, n):
    if i < n:
        temp = TreeNode(arr[i])
        root = temp
        root.left = insert_level_order(arr, root.left, 2*i + 1, n)
        root.right = insert_level_order(arr, root.right, 2*i + 2, n)
    return root

def print_tree(root, space=0, level=0):
    if root is None:
        return
    space += 5
    print_tree(root.right, space, level + 1)
    print()
    for i in range(5, space):
        print(end=" ")
    print(root.val)
    print_tree(root.left, space, level + 1)

def display_binary_tree(arr):
    n = len(arr)
    root = None
    root = insert_level_order(arr, root, 0, n)
    print("Binary Tree:")
    print_tree(root)

# arr = [0, 1, 8, 9, 12, 13, 14, 18, 19, 20, 21, 22, 24, 25, 26, 30, 32, 34, 35, 36, 37, 38, 40, 41, 42, 43, 44, 45, 46, 49, 50]
# arr = [22, 13, 8, 0, 1, 9, 12, 18, 14, 21, 20, 19, 35, 30, 24, 26, 25, 34, 32, 41, 37, 36, 40, 38, 45, 43, 42, 44, 49, 46, 51]
arr = [1, 0, 12, 9, 8, 14, 19, 20, 21, 18, 13, 25, 26, 24, 32, 34, 30, 36, 38, 40, 37, 42, 44, 43, 46, 50, 49, 45, 41, 35, 22]
display_binary_tree(arr)