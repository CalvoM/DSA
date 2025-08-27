class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isSymmetric(self, root: TreeNode | None):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """

        vals = self.bfs(root)
        power = 0
        while True:
            max_length = 2**power
            vals_to_inspect = vals[0:max_length]
            if vals_to_inspect != list(reversed(vals_to_inspect)):
                return False
            [vals.pop(0) for i in range(max_length)]
            power += 1
            if len(vals) <= 0:
                break
        return True

    def bfs(self, root: TreeNode) -> list[None | TreeNode]:
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
