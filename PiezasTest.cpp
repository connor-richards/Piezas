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

TEST(PiezasTest, sanityCheck)
{
  Piezas game;
  if(game.gameState() == Invalid) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}
