import random 
from random import shuffle


def generate_board(n):
    board = random.sample(range(n), n)
    return board


def crossing(board):
    cross = 0
    for i in range(len(board)):
        for j in range(i +1, len(board)):
            offset = j - i
            if board[i] == board[j] - offset or board[i] == board[j] + offset:
                cross += 1  
    return cross                   


def hill_climb(best_result, k):
    for i in range(k):
        if best_result["cross"] == 0:
            print(f'Solved: {best_result}')
            break
        else:
            to_beat = {}
            board_copy = best_result["board"]
            random.shuffle(board_copy)
            copy_cross = crossing(board_copy)
            to_beat["board"] = board_copy
            to_beat["cross"] = copy_cross
            if to_beat["cross"] < best_result["cross"]:
                best_result = to_beat 
                print(f'Best result: {best_result}')
            

if __name__ == "__main__":
    n = int(input("Enter the number of Queens: "))
    k = 500                 # number of iterations
    best_result = {}
    best_result["board"] = generate_board(n)
    best_result["cross"] = crossing(best_result["board"]) 
    print(f'Starting point: {best_result}')
    hill_climb(best_result, k)
