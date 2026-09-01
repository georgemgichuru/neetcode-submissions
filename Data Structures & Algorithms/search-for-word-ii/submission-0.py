class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # build Trie
        root = {}
        for word in words:
            node = root
            for char in word:
                if char not in node:
                    node[char] = {}
                node = node[char]
            node['#'] = word
        rows, cols = len(board), len(board[0])
        result = []

        def dfs(i, j, node):
            char = board[i][j]
            if char not in node:
                return
            
            next_node = node[char]
            if '#' in next_node:
                result.append(next_node['#'])
                del next_node['#']
            
            board[i][j] = '*'
            for di,dj in [(0,1), (0,-1), (1,0), (-1,0)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < rows and 0 <= nj < cols and board[ni][nj] != '*':
                    dfs(ni, nj, next_node)
            board[i][j] = char

            if not next_node:
                del node[char]
        
        for i in range(rows):
            for j in range(cols):
                dfs(i,j, root)
        return result
