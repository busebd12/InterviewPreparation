class TrieNode:
    def __init__(self, name: str, is_directory: bool):
        self.children=dict()

        self.name=name

        self.contents=""

        self.is_directory=is_directory

class Trie:
    def __init__(self):
        self.root=TrieNode("/", True)

    def get_directory_contents(self, path: str) -> List[str]:
        node=self.root

        for item in self.tokenize_path(path, "/"):
            if item not in node.children.keys():
                return []
            
            node=node.children[item]

        if not node.is_directory:
            return [node.name]

        return sorted([element.name for element in node.children.values()])

    def insert(self, path: str) -> None:
        node=self.root

        for item in self.tokenize_path(path, "/"):
            if item not in node.children.keys():
                node.children[item]=TrieNode(item, True)

            node=node.children[item]

    def append_content(self, path: str, file_contents: str) -> None:
        node=self.root

        for item in self.tokenize_path(path, "/"):
            if item not in node.children.keys():
                node.children[item]=TrieNode(item, True)

            node=node.children[item]

        node.is_directory=False

        node.contents+=file_contents

    def get_file_contents(self, path: str) -> str:
        node=self.root

        for item in self.tokenize_path(path, "/"):
            if item not in node.children.keys():
                return ""

            node=node.children[item]

        return node.contents

    def tokenize_path(self, path: str, delimiter: str) -> List[str]:
        tokens=[token for token in path.split(delimiter) if token]

        return tokens

class FileSystem:
    def __init__(self):
        self.root=Trie()

    def ls(self, path: str) -> List[str]:
        return self.root.get_directory_contents(path)

    def mkdir(self, path: str) -> None:
        self.root.insert(path)

    def addContentToFile(self, filePath: str, content: str) -> None:
        self.root.append_content(filePath, content)

    def readContentFromFile(self, filePath: str) -> str:
        return self.root.get_file_contents(filePath)