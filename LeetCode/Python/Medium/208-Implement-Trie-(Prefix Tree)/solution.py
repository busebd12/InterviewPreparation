class TrieNode:
    def __init__(self):
        self.children: Dict[chr, TrieNode]=dict()

        self.end_of_word: bool=False

class Trie:
    def __init__(self):
        self.root: TrieNode=TrieNode()

    def insert(self, word: str) -> None:
        node: TrieNode=self.root

        for character in word:
            if character not in node.children.keys():
                node.children[character]=TrieNode()
            
            node=node.children[character]

        node.end_of_word=True

    def search(self, word: str) -> bool:
        node: TrieNode=self.root

        for character in word:
            if character not in node.children.keys():
                return False

            node=node.children[character]

        return node.end_of_word

    def startsWith(self, prefix: str) -> bool:
        node: TrieNode=self.root

        for character in prefix:
            if character not in node.children.keys():
                return False

            node=node.children[character]

        return True