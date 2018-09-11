#!/usr/bin/env python
#-*- coding:utf-8 -*-


import random

YuanSu = ['1','2','3','4','5','6','7','8','9']
INDEX = [0,1,2,3,4,5,6,7,8]


def CreateBoard():
    '''创建一个标准棋盘,即棋盘大小为9×9'''
    board = []  
    for i in range(9):
        row = ['.']*9
        number = random.randint(1,9)  #产生随机数的个数
        list_nums = []
        for j in range(number):
            num = random.choice(['1','2','3','4','5','6','7','8','9'])  #从YuanSu中随机选取number个元素
            list_nums.append(num)
        list_index = random.sample([0,1,2,3,4,5,6,7,8],number)  #从INDEX中随机生成上面随机元素的索引
        for index in range(number):
            row[list_index[index]] = list_nums[index]
        board.append(row)
    return board


def IsRowValid(board):
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


def IsColumnValid(board):
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


def SeparateBoard(board):
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


def IsSubBoxesValid(list_Board):
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
    

def IsValidSudoku(board):
    a = IsRowValid(board)
    b = IsColumnValid(board)
    list_Board = SeparateBoard(board)
    c = IsSubBoxesValid(list_Board)
    if a and b and c:
        return True
    else:
        return False

    

def CreateValidBoard():
    ##产生一个随机棋盘，并判断其是否有效
    board = CreateBoard()
    BOOL = IsValidSudoku(board)
    #print(BOOL)

    ##若棋盘无效，则继续创建新的棋盘，直至找到一个有效的棋盘
    i = 0
    while not BOOL:    
        board = CreateBoard()
        i += 1
        BOOL = IsValidSudoku(board)
    print(i)
    validBoard = board
    ##将最终的有效棋盘打印出来
    for i in range(9):
        print(validBoard[i])
    return validBoard

CreateValidBoard()
