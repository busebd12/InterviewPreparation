class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        result: List[Optional[TreeNode]]=list()

        root_start: int=1

        root_end: int=n

        result=self.solve(root_start, root_end)

        return result
        
    def solve(self, root_start: int, root_end: int) -> List[Optional[TreeNode]]:
        #If there are no more root nodes available, then just return a TreeNode with value None
        if root_start > root_end:
            return [None]

        trees: List[Optional[TreeNode]]=list()

        #Iterate through all possible root values for the current tree
        for root in range(root_start, root_end + 1):
            #If we select the root node value for the current tree to be root, then the remaining possible root values
            #for the left subtrees are in the range [root_start, root - 1] since, in a binary search tree, all nodes
            #to the left of the root have to be less than the root
            left_subtrees: List[Option[TreeNode]]=self.solve(root_start, root - 1)

            #If we select the root node value for the current tree to be root, then the remaining possible root values
            #for the right subtrees are in the range [root + 1, root_end] since, in a binary search tree, all nodes to
            #the right of the root have to greater than the root
            right_subtrees: List[Optional[TreeNode]]=self.solve(root + 1, root_end)

            #Iterate through all possible left subtrees
            for left_subtree in left_subtrees:
                #Iterate through all possible right subtrees
                for right_subtree in right_subtrees:
                    #Build the actual root node for the current tree
                    root_node: TreeNode=TreeNode(root, left_subtree, right_subtree)
                    #Add the tree to the list of trees
                    trees.append(root_node)

        return trees