class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        a = self.IsRowValid(board)
        b = self.IsColumnValid(board)
        list_Board = self.SeparateBoard(board)
        c = self.IsSubBoxesValid(list_Board)
        if a and b and c:
            return True
        else:
            return False
        
        
    def IsRowValid(self, board):
        '''通过每一行验证上面创建的棋盘是否合理'''
        flag = True
        for row in range(9):
            list_row = []
            for column in range(9):
                if board[row][column] == '.':
                    continue
                elif board[row][column] not in list_row:
                    list_row.append(board[row][column])
                else:
                    flag = False
                    break
            if flag == False:
                return False
        return True


    def IsColumnValid(self, board):
        '''通过每一列验证上面创建的棋盘是否合理'''
        flag = True
        for column in range(9):
            list_column = []
            for row in range(9):
                if board[row][column] == '.':
                    continue
                elif board[row][column] not in list_column:
                    list_column.append(board[row][column])
                else:
                    flag = False
                    break
            if flag == False:
                return False          
        return True


    def SeparateBoard(self, board):
        b1 = []
        b2 = []
        b3 = []
        b4 = []
        b5 = []
        b6 = []
        b7 = []
        b8 = []
        b9 = []    
        for i in range(3):
            for j in range(3):
                b1.append(board[i][j])
                b2.append(board[i][j + 3])
                b3.append(board[i][j + 2*3])
                
                b4.append(board[i + 3][j])
                b5.append(board[i + 3][j + 3])
                b6.append(board[i + 3][j + 2*3])

                b7.append(board[i + 2*3][j])
                b8.append(board[i + 2*3][j + 3])
                b9.append(board[i + 2*3][j + 2*3])
        list_Board = [b1,b2,b3,b4,b5,b6,b7,b8,b9]
        return list_Board


    def IsSubBoxesValid(self, list_Board):
        flag = True
        for i in range(len(list_Board)):
            L = list_Board[i]
            list_L = []
            for j in range(len(L)):
                if L[j] == '.':
                    continue
                elif L[j] not in list_L:
                    list_L.append(L[j])
                else:
                    flag = False
                    break
        if flag == False:
                return False          
        return True    
