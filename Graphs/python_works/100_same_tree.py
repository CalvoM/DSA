from collections import deque


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """

        vals = self.bfs(root)
        print(vals)
        power = 0
        while True:
            if len(vals) <= 0:
                break
            max_length = 2**power
            vals_to_inspect = vals[0:max_length]
            print(len(vals_to_inspect), max_length)
            if len(vals_to_inspect) < max_length:
                vals_to_inspect.extend([None] * (max_length - len(vals_to_inspect)))
            if vals_to_inspect != list(reversed(vals_to_inspect)):
                return False
            print(vals, max_length)
            try:
                [vals.pop(0) for i in range(max_length)]
            except IndexError:
                return False
            power += 1
            if len(vals) <= 0:
                break
        return True

    def bfs(self, root):
        if not root:
            return [None]

        queue = deque([root])
        vals = []

        while queue:
            node = queue.popleft()
            if node:
                vals.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                vals.append(None)

        return vals
