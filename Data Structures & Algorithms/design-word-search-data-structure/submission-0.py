class WordDictionary:
    def __init__(self):
        self.root = {}

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node:
                node[char] = {}
            node = node[char]
        node['#'] = True

    def search(self, word: str) -> bool:
        def helper(index, node):
            if not node:
                return False
            if index == len(word):
                return '#' in node

            char = word[index]
            if char == '.':
                for child in node:
                    if child != '#' and helper(index + 1, node[child]):
                        return True
                return False
            else:
                if char not in node:
                    return False
                return helper(index + 1, node[char])

        return helper(0, self.root)