from pade.core.agent import Agent
from pade.acl.messages import ACLMessage
from pade.acl.aid import AID
from pade.misc.utility import display_message, start_loop, call_later


import itertools
import random
import copy


"""Board positions:
 --- --- --- 
| 8 | 3 | 4 |
 --- --- --- 
| 1 | 5 | 9 |
 --- --- --- 
| 6 | 7 | 2 |
 --- --- --- 
"""

class TicTacToe:
    def __init__(self):
        self.order = 3
        self.players = ['X', 'O']
        self.winner = None
        
        self.board = [
            [' ', ' ', ' '],
            [' ', ' ', ' '],
            [' ', ' ', ' ']
        ]
        
        self.board_pos = {
            1 : (1, 0),
            2 : (2, 2),
            3 : (0, 1),
            4 : (0, 2),
            5 : (1, 1),
            6 : (2, 0),
            7 : (2, 1),
            8 : (0, 0),
            9 : (1, 2)
        }
        
        self.squares_played = {
            'X' : [],
            'O' : []
        }
        
        self.empty_positions = [i for i in range(1, self.order * self.order + 1)]
        
        XO_dict = {'X' : 0, 'O' : 0}
        self.sums = {
            'row' : [XO_dict.copy() for i in range(self.order)],
            'col' : [XO_dict.copy() for i in range(self.order)],
            'diag': XO_dict.copy(),
            'anti': XO_dict.copy()
        }
        
    def print_board(self):
        print(" --- --- --- ")
        for row in self.board:
            print(f"| {row[0]} | {row[1]} | {row[2]} |")
            print(" --- --- --- ")
    
    def print_board_positions(self):
        b = copy.deepcopy(self.board)
        for i in range(1, self.order * self.order + 1):
            row, col = self.board_pos[i]
            b[row][col] = i
            
        print(" --- --- --- ")
        for row in b:
            print(f"| {row[0]} | {row[1]} | {row[2]} |")
            print(" --- --- --- ")
    
    def is_winner(self, player, pos):
        position = self.board_pos[pos]
        row, col = position
        
        if (self.sums['row'][row][player] == 15 or self.sums['col'][col][player] == 15 or
            self.sums['diag'][player] == 15 or self.sums['anti'][player] == 15):
            return True
        
        return False
    
    def make_move(self, player, pos):
        position = self.board_pos[pos]
        row, col = position
        if (self.board[row][col] != ' '):
            print("Can't play this move since position is already taken.")
            return False
        
        self.board[row][col] = player
        self.squares_played[player].append(pos)
        
        self.sums['row'][row][player] += pos
        self.sums['col'][col][player] += pos
        
        if (row == col):
            self.sums['diag'][player] += pos
        if (row + col == self.order-1):
            self.sums['anti'][player] += pos
        
        return True

class HumanAgent(Agent):
    def __init__(self, aid):
        super().__init__(aid=aid)

    def decide_move(self):
        pos = int(input("Enter the position (1-9) to make move on: "))
        return pos

class ComputerAgent(Agent):
    def __init__(self, aid, idx, ttt):
        super().__init__(aid=aid)
        self.idx = idx
        self.ttt = ttt
        self.current_player = self.ttt.players[idx]
        self.opponent_player = self.ttt.players[idx ^ 1]
        
    def poss_win(self, player):
        played = self.ttt.squares_played[player]
        if (len(played) < 2):
            # player has played less than 2 squares, so can't win
            return 0
        for pair in itertools.combinations(played, r=2):
            #print("-----")
            need = 15 - sum(pair)
            #print(f'Pair: {pair}, Need: {need}')
            if (not(need <= 0 or need > 9)):
                # squares are collinear
                row, col = self.ttt.board_pos[need]
                if (self.ttt.board[row][col] == ' '):
                    return need
            #print("-----")
        return 0
    
    def create_fork(self):
        pos = 0
        return pos
    
    def block_opponent_fork(self):
        pos = 0
        return pos
    
    def move_opposite_corner(self):
        pos = 0
        played = self.ttt.squares_played[self.current_player]
        for s in played:
            if (s == 8 or s == 4 or s == 6 or s == 2):
                need = 10 - s
                row, col = self.ttt.board_pos[need]
                if (self.ttt.board[row][col] == ' '):
                    pos = need
                    return pos
        return 0
    
    def move_empty_corner(self):
        corners = [8, 4, 6, 2]
        for c in corners:
            row, col = self.ttt.board_pos[c]
            if (self.ttt.board[row][col] == ' '):
                return c
        return 0
    
    def move_empty_side(self):
        sides = [3, 1, 9, 7]
        for s in sides:
            row, col = self.ttt.board_pos[s]
            if (self.ttt.board[row][col] == ' '):
                return s
        return 0
    
    def decide_move(self, idx):
        current_win_move = self.poss_win(self.current_player)
        opponent_win_move = self.poss_win(self.opponent_player)
        
        if (current_win_move != 0):
            # win
            print(f'current player can win by playing at {current_win_move}')
            pos = current_win_move
        
        elif (opponent_win_move != 0):
            # block opponent's winning chance
            print(f'opponent can win by playing at {opponent_win_move}')
            print('current player blocking opponent win move')
            pos = opponent_win_move
        
        else:
            fork_pos = self.create_fork()
            opponent_fork_pos = self.block_opponent_fork()
            if (fork_pos != 0):
                pos = fork_pos
            
            elif (opponent_fork_pos != 0):
                pos = opponent_fork_pos
            
            elif (self.ttt.board[1][1] == ' '):
                # move center
                pos = 5
            
            else:
                opp_corner = self.move_opposite_corner()
                if (opp_corner != 0):
                    pos = opp_corner
                
                else:
                    empty_corner = self.move_empty_corner()
                    if (empty_corner != 0):
                        pos = empty_corner
                    
                    else:
                        empty_side = self.move_empty_side()
                        pos = empty_side
        return pos

def start_playing(ttt):
    # convention : X goes first
    # if human is X, then human goes first; otherwise, computer
    
    idx = 0
    ask = """Who goes first (1-2)?\n1. Human\n2. Computer\nWhoever goes first will be the 'X' player: """
    goes_first = int(input(ask))
    if (goes_first == 1):
        human = ttt.players[idx] # X
        computer = ttt.players[idx ^ 1] # O
    else:
        human = ttt.players[idx ^ 1] # O
        computer = ttt.players[idx] # X
    
    port = 20000
    human_agent = HumanAgent(AID(name=f'human@localhost:{port}'))
    computer_agent = ComputerAgent(AID(name=f'computer@localhost:{port+10}'), idx ^ 1, ttt)
    
    turn = 1
    
    while (turn <= ttt.order * ttt.order):
        current_player = ttt.players[idx]
        
        print(f"\n=> Turn {turn}: player {current_player}'s turn")
        
        if current_player == human:
            pos = human_agent.decide_move()
            
        else:
            # computer with artificial "intelligence"
            if (turn == 1):
                corner_pos = computer_agent.move_empty_corner()
                if (corner_pos != 0):
                    pos = corner_pos
            else:
                pos = computer_agent.decide_move(idx)
                
        position = ttt.board_pos[pos]
        print(f'Player {current_player} is making move at position {position}...')
        
        if (ttt.make_move(current_player, pos) == False):
            continue
        else:
            turn += 1
            ttt.empty_positions.remove(pos)
            ttt.print_board()
            if(ttt.is_winner(current_player, pos)):
                print(f'Player "{current_player}" has won!')
                ttt.winner = current_player
                break
            # swapping the turn can be done simply by XORing with 1.
            idx = idx ^ 1
    if (turn == 10 and ttt.winner == None):
        print('The game has tied!')

if __name__ == '__main__':

    ttt = TicTacToe()
    print("  TIC-TAC-TOE   ")
    print("Board positions:")
    ttt.print_board_positions()
    print()

    start_playing(ttt)
