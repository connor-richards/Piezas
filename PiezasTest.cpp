/**
 * Unit Tests for Piezas
 **/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
  protected:
    PiezasTest(){} //constructor runs before each test
    virtual ~PiezasTest(){} //destructor cleans up after tests
    virtual void SetUp(){} //sets up before each test (after constructor)
    virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, invalidDrop)
{
  Piezas game;
  if(game.dropPiece(90) == Invalid) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, dropOnFilledSpace)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
  if(game.dropPiece(0) == Blank) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, emptyGame)
{
  Piezas game;
  if(game.gameState() == Invalid) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, simpleTie)
{
  Piezas game;
  for(int idx=0; idx<4; idx++) {
    for(int idx2=0; idx2<3; idx2++) {
      game.dropPiece(idx);
    }
  }
  if(game.gameState() == Blank) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, simpleXWin)
{
  Piezas game;
  for(int idx=0; idx<4; idx++) {
    game.dropPiece(idx);
    game.dropPiece(idx+99);
    game.dropPiece(idx);
    game.dropPiece(idx+99);
    game.dropPiece(idx);
    game.dropPiece(idx+99);
  }
  if(game.gameState() == X) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, simpleOWin)
{
  Piezas game;
  for(int idx=0; idx<4; idx++) {
    game.dropPiece(idx+99);
    game.dropPiece(idx);
    game.dropPiece(idx+99);
    game.dropPiece(idx);
    game.dropPiece(idx+99);
    game.dropPiece(idx);
  }
  if(game.gameState() == O) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, filledBoardReset)
{
  Piezas game;
  for(int idx=0; idx<4; idx++) {
    for(int idx2=0; idx2<3; idx2++) {
      game.dropPiece(idx);
    }
  }
  game.reset();
  if(game.gameState() == Invalid) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, simplePieceAt)
{
  Piezas game;
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(3);
  if(game.pieceAt(0,3) == X &&
      game.pieceAt(0,2) == O &&
      game.PieceAt(1,3) == X &&
      game.PieceAt(2,3) == O) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, invalidPieceAt)
{
  Piezas game;
  if(game.pieceAt(0,90) == Invalid) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, blankPieceAt)
{
  Piezas game;
  if(game.pieceAt(0,0) == Blank) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}
