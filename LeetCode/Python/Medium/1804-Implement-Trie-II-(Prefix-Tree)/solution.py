class TrieNode:
    def __init__(self):
        self.children=dict()

        self.prefix_count=0

        self.frequency=0

        self.end_of_word=False

class Trie:
    def __init__(self):
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        node=self.root

        for character in word:
            if character not in node.children.keys():
                node.children[character]=TrieNode()

            node=node.children[character]

            node.prefix_count+=1

        if node.end_of_word==False:
            node.end_of_word=True

        node.frequency+=1

    def countWordsEqualTo(self, word: str) -> int:
        node=self.root

        count=0

        for character in word:
            if character not in node.children.keys():
                return 0

            node=node.children[character]

        if node.end_of_word:
            count+=node.frequency
        
        return count

    def countWordsStartingWith(self, prefix: str) -> int:
        node=self.root

        count=0

        for character in prefix:
            if character not in node.children.keys():
                return 0

            node=node.children[character]

        count+=node.prefix_count

        return count

    def erase(self, word: str) -> None:
        node=self.root
        
        for character in word:
            node=node.children[character]

            if node.prefix_count > 0:
                node.prefix_count-=1

        if node.end_of_word:
            if node.frequency > 0:
                node.frequency-=1

                if node.frequency==0:
                    node.end_of_word=False