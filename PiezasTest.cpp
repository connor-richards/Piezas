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

TEST(PiezasTest, sanityCheck)
{
  ASSERT_TRUE(true);
}

TEST(PiezasTest, emptyGame)
{
  Piezas game;
  if(game.gameState() == Invalid) {
    ASSERT_TRUE(true);
  }
  ASSERT_TRUE(false);
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
  ASSERT_TRUE(false);
}

TEST(PiezasTest, simpleWin)
{
  Piezas game;
  game.dropPiece(idx); //TODO drop rest of pieces for win
ASSERT_TRUE(true); //TODO
  if(game.gameState() == Blank) {
    ASSERT_TRUE(true);
  }
  ASSERT_TRUE(false);
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
  ASSERT_TRUE(false);
}

TEST(PiezasTest, invalidDrop)
{
  Piezas game;
  if(game.dropPiece(90) == Invalid) {
    ASSERT_TRUE(true);
  }
  ASSERT_TRUE(false);
}
