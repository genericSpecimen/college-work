from pade.misc.utility import display_message, start_loop
from pade.core.agent import Agent
from pade.acl.aid import AID
from pade.acl.messages import ACLMessage

from math import inf
import itertools
#import random
import copy

class TicTacToe:
    def __init__(self, order, player1, player2, start):
        self.player1 = player1
        self.player2 = player2
        self.start = start

        self.order = order
        self.turn = 1
        self.players = ['X', 'O']
        self.winner = None
        
        self.board = [[' ' for j in range(1, self.order+1)] for i in range(1, self.order+1)]
        
        self.empty_positions = [i for i in range(1, self.order * self.order + 1)]
        #print(self.empty_positions)
        
        XO_dict = {'X' : 0, 'O' : 0}
        self.sums = {
            'row' : [XO_dict.copy() for i in range(self.order)],
            'col' : [XO_dict.copy() for i in range(self.order)],
            'diag': XO_dict.copy(),
            'anti': XO_dict.copy()
        }
        
    def print_board(self):
        print(" ", end="")
        for i in range(0, self.order):
            print("---", end=" ")
        print()
        #print(" --- --- --- ")
        for row in self.board:
            
            print("|", end=" ")
            for i in range(0, self.order):
                print(row[i], end=" | ")
            #print(f"| {row[0]} | {row[1]} | {row[2]} |")
            
            print()
            
            print(" ", end="")
            for i in range(0, self.order):
                print("---", end=" ")
            print()
    
    def print_board_positions(self):
        b = copy.deepcopy(self.board)
        row = 0
        col = 0

        for (i, j) in list(itertools.product(range(0, self.order), range(0, self.order))):
            pos_int = i * self.order + j + 1
            b[i][j] = pos_int
        
        print(" ", end="")
        for i in range(0, self.order):
            print("---", end=" ")
        print()
        #print(" --- --- --- ")
        for row in b:
            
            print("|", end=" ")
            for i in range(0, self.order):
                print(row[i], end=" | ")
            #print(f"| {row[0]} | {row[1]} | {row[2]} |")
            
            print()
            
            print(" ", end="")
            for i in range(0, self.order):
                print("---", end=" ")
            print()

    
    def is_winner(self, player, pos):
        row = (pos-1) // ttt.order
        col = (pos-1) % ttt.order
        # check winner
        if (self.sums['row'][row][player] == self.order or self.sums['col'][col][player] == self.order or
            self.sums['diag'][player] == self.order or self.sums['anti'][player] == self.order):
            return True
        
        return False
    
    def make_move(self, player, pos):
        #position = self.board_pos[pos]
        #row, col = position
        row = (pos-1) // ttt.order
        col = (pos-1) % ttt.order
        if (self.board[row][col] != ' '):
            print("Can't play this move since position is already taken.")
            return False
        
        self.board[row][col] = player
        self.empty_positions.remove(pos)
        
        self.sums['row'][row][player] += 1
        self.sums['col'][col][player] += 1
        
        if (row == col):
            self.sums['diag'][player] += 1
        if (row + col == self.order-1):
            self.sums['anti'][player] += 1
        
        return True
    
    def undo_move(self, player, pos):
        row = (pos-1) // ttt.order
        col = (pos-1) % ttt.order
        if (self.board[row][col] == ' '):
            print("Can't undo this move since position is empty.")
            return False
        
        self.board[row][col] = ' '
        self.empty_positions.append(pos)
        
        self.sums['row'][row][player] -= 1
        self.sums['col'][col][player] -= 1
        
        if (row == col):
            self.sums['diag'][player] -= 1
        if (row + col == self.order-1):
            self.sums['anti'][player] -= 1
        
        return True


utilities_MAX = {
    'X' : 1,
    'O' : -1,
    'tie': 0
}

utilities_MIN = {
    'X' : -1,
    'O' : 1,
    'tie': 0
}

utilities = None

def terminal_state(ttt, player, pos):
    utility = None
    if (ttt.is_winner(player, pos)):
        utility = utilities[player]
    elif (ttt.empty_positions == []):
        utility = utilities['tie']
    return utility


def minimax_best_move(ttt, isMAX, alpha, beta):
    if (isMAX):
        # current player is MAX (X)
        v = -inf
        player = 'X'
        
        best_move = None
        
        for pos in ttt.empty_positions:
            ttt.make_move(player, pos)
            
            utility = terminal_state(ttt, player, pos)
            if (utility != None):
                ttt.undo_move(player, pos)
                return (pos, utility)
            
            # next move is to be made by MIN, so isMAX = False
            _, v_poss = minimax_best_move(ttt, False, alpha, beta)
            
            ttt.undo_move(player, pos)
            
            # current (maximizing) player will try to maximize the values returned
            #v = max(v, v_poss)
            
            if(v_poss > v):
                v = v_poss
                best_move = pos
            
            # MAX updates its alpha
            alpha = max(alpha, v)
            if (alpha >= beta):
                # MIN has a move where it can have a score v <= beta, which
                # is less than alpha, so, MIN will choose that move instead.
                # beta cutoff
                break
        return (best_move, v)
    else:
        # current player is MIN (O)
        v = inf
        player = 'O'
        
        best_move = None
        
        for pos in ttt.empty_positions:
            ttt.make_move(player, pos)

            utility = terminal_state(ttt, player, pos)
            if (utility != None):
                ttt.undo_move(player, pos)
                return (pos, utility)
            
            # next move is to be made by MAX, so isMAX = True
            _, v_poss = minimax_best_move(ttt, True, alpha, beta)
            
            ttt.undo_move(player, pos)
            
            # current (minimizing) player will try to minimize the values returned
            #v = min(v, v_poss)
            
            if (v_poss < v):
                v = v_poss
                best_move = pos
            
            # MIN updates beta
            beta = min(beta, v)
            if (beta <= alpha):
                # MAX has a move where it can have a score v >= alpha, which
                # is more than beta, so, MAX will choose that move instead.
                # alpha cutoff
                break
        return (best_move, v)

def minimax_decision(ttt, player):
    # maintain the minimum score that the maximizing player is assured of
    alpha = -inf
    
    # maintain the maximum score that the minimizing player is assured of
    beta = inf
    
    pos = None
    
    global utilities
    
    if (player == 'X'):
        utilities = utilities_MAX
        pos, _ = minimax_best_move(ttt, True, alpha, beta)
    else:
        utilities = utilities_MIN
        pos, _ = minimax_best_move(ttt, False, alpha, beta)
    return pos

class Player(Agent):
    def __init__(self, aid, mark):
        super().__init__(aid)
        self.ttt = None
        self.opponent = None
        self.mark = mark

    def on_start(self):
        super().on_start()

        if self.ttt.start == self:
            self.next_move()

    def join_game(self, ttt):
       self.ttt = ttt
       self.opponent = (self.ttt.player1 if (self != self.ttt.player1) else self.ttt.player2)


    def react(self, message):
        super().react(message)
        self.next_move()

    # sends "your turn" message to opponent
    def send_message(self):
        message = ACLMessage(ACLMessage.INFORM)
        message.set_protocol(ACLMessage.FIPA_REQUEST_PROTOCOL)
        message.set_content("Your turn")
        message.add_receiver(self.opponent.aid)
        self.agentInstance.table[self.opponent.aid.localname] = self.opponent.aid

        self.call_later(1, self.send, message)

class HumanPlayer(Player):
    def __init__(self, aid, mark):
        super().__init__(aid, mark)

    def next_move(self):
        #self.game.print_board()
        display_message(self.aid.localname, f'Turn {self.ttt.turn} : ' + self.aid.localname + "'s turn")
        pos = int(input("Enter the position to make your move on: "))
        
        while (ttt.make_move(self.mark, pos) == False):
            pos = int(input("Enter the position to make your move on: "))
        
        self.ttt.turn += 1
        self.ttt.print_board()
        if(self.ttt.is_winner(self.mark, pos)):
            print(f'Player "{self.mark}" has won!')
            self.ttt.winner = self.mark
            return
        
        if (self.ttt.turn == self.ttt.order*self.ttt.order+1 and self.ttt.winner == None):
            print('The game has tied!')
            return
        
        self.send_message()


class ComputerPlayer(Player):
    def __init__(self, aid, mark):
        super().__init__(aid, mark)

    def next_move(self):
        #self.game.print_board()
        display_message(self.aid.localname, f'Turn {self.ttt.turn} : ' + self.aid.localname + "'s turn")
        
        pos = minimax_decision(self.ttt, self.mark)
        
        self.ttt.make_move(self.mark, pos)
        
        self.ttt.turn += 1
        self.ttt.print_board()
        if(self.ttt.is_winner(self.mark, pos)):
            print(f'Player "{self.mark}" has won!')
            self.ttt.winner = self.mark
            return
        
        if (self.ttt.turn == self.ttt.order*self.ttt.order+1 and self.ttt.winner == None):
            print('The game has tied!')
            return

        self.send_message()

if __name__ == '__main__':
    ask = """Who goes first (1-2)?\n1. Human\n2. Computer\nWhoever goes first will be the 'X' player: """
    goes_first = int(input(ask))
    
    order = 3
    
    if goes_first == 1:
        human = HumanPlayer(AID('human'), 'X')
        computer = ComputerPlayer(AID('computer'), 'O')
        ttt = TicTacToe(order, human, computer, start=human)
    else:
        human = HumanPlayer(AID('human'), 'O')
        computer = ComputerPlayer(AID('computer'), 'X')
        ttt = TicTacToe(order, human, computer, start=computer)
    
    human.join_game(ttt)
    computer.join_game(ttt)
    
    print("  TIC-TAC-TOE   ")
    print("Board positions:")
    
    #ttt.print_board()
    ttt.print_board_positions()
    
    agents = [human, computer]
    start_loop(agents)

