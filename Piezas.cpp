#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
 **/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
 **/
Piezas::Piezas()
{
  turn = X;
  Piece empty = Blank;
  for(int row=0; row<3; row++) {
    std::vector<Piece> tmp;
    for(int col=0; col<4; col++) {
      tmp.push_back(empty);
    }
    board.push_back(tmp);
  }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
 **/
void Piezas::reset()
{
  for(int row=0; row<3; row++) {
    for(int col=0; col<4; col++) {
      board[row][col] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
 **/ 
Piece Piezas::dropPiece(int column)
{
  Piece cur;
  if(turn==X) {
    turn=O;
    cur=X;
  }
  else {
    turn=X;
    cur=O;
  }

  if(column > 3) {
    return Invalid;
  }
  else if(board[2][column]==Blank) {
    board[2][column]=cur;
    return cur;
  }
  else if(board[1][column]==Blank) {
    board[1][column]=cur;
    return cur;
  }
  else if(board[0][column]==Blank) {
    board[0][column]=cur;
    return cur;
  }
  else {
    return Blank;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece Piezas::pieceAt(int row, int column)
{
  if(row>2 || column>3) {
    return Invalid;
  }
  if(row==2) {
    return board[0][column];
  }
  if(row==0) {
    return board[2][column];
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 **/
Piece Piezas::gameState()
{
  /* vars to keep track of longest lines */
  int omax = 0, xmax = 0, curo = 0, curx = 0;

  /* iterate through to check for blank spaces */
  for(int row=0; row<3; row++) {
    for(int col=0; col<4; col++) {
      if(board[row][col] == Blank) {
        /* blank space, game not over */
        return Invalid;
      }
    }
  }

  /* vertical */
  for(unsigned int col=0; col<board[0].size(); col++) {
    for(unsigned int row=0; row<board.size(); row++) {
      if(board[row][col] == X) {
        curo = 0;
        curx++;
        if(curx > xmax) {
          xmax = curx;
        }
      }
      else if(board[row][col] == O) {
        curx = 0;
        curo++;
        if(curo > omax) {
          omax = curo;
        }
      }
    }
  }

  /* horizontal */
  for(unsigned int row=0; row<board.size(); row++) {
    for(unsigned int col=0; col<board[row].size(); col++) {
      if(board[row][col] == X) {
        curo = 0;
        curx++;
        if(curx > xmax) {
          xmax = curx;
        }
      }
      else if(board[row][col] == O) {
        curx = 0;
        curo++;
        if(curo > omax) {
          omax = curo;
        }
      }
    }
  }

  /* O wins */
  if(omax > xmax) {
    return O;
  }
  /* X wins */
  else if(xmax > omax) {
    return X;
  }
  /* tie */
  else {
    return Blank;
  }
}
