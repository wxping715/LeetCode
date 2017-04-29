class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.search(board, 0, 0)
    
    def candicates(self, board, x, y):
        cands = range(1, 10)
        cur = []
        for j in xrange(0, 9):
            if board[x][j] != '.':
                cur.append(int(board[x][j]))
        
        for i in xrange(0, 9):
            if board[i][y] != '.':
                cur.append(int(board[i][y]))
        
        ri, ci = x/3, y/3
        for i in xrange(0, 3):
            for j in xrange(0, 3):
                if board[ri*3+i][ci*3+j] != '.':
                    cur.append(int(board[ri*3+i][ci*3+j]))
        
        res = list(set(cands).difference(cur))
        # print board
        # print x, y, res
        return res
    
    def search(self, board, x, y):
        while x < 9 and y < 9:
            if board[x][y] == '.':
                break
            
            y += 1
            if y >= 9:
                y = 0
                x += 1
        
        # fill all numbers
        if x >= 9 or y >= 9:
            if self.check(board):
                return True
            return False
        
        # need to fill numbers
        cands = self.candicates(board, x, y)
        # no candicates, break on time
        if not cands:
            return False
            
        for num in cands:
            board[x][y] = chr(num+ord('0'))
            res = self.search(board, x, y)
            if res:
                return True
        board[x][y] = '.'
        return False
            
    def check(self, board):
        # check rows
        for i in xrange(0, 9):
            hash = {}
            for j in xrange(0, 9):
                hash[board[i][j]] = 1
            if len(hash) != 9:
                return False
        
        # check cols
        for j in xrange(0, 9):
            hash = {}
            for i in xrange(0, 9):
                hash[board[i][j]] = 1
            if len(hash) != 9:
                return False
                
        # check rectangle
        for i in xrange(0, 3):
            for j in xrange(0, 3):
                hash = {}
                for k in xrange(0, 3):
                    for r in xrange(0, 3):
                        hash[board[i*3+k][j*3+r]] = 1
                if (len(hash) != 9):
                    return False
        return True
