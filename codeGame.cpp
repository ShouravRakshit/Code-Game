#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



void PrintIntro(int level){

    std::cout << "\n***** You have entered into restricted area level "   << level  << " *****\n";
    std::cout << "***** So you need to enter correct code to escape bruh ***** \n \n" ;

}



bool PlayGame(int difficulty) {

  // Setting the difficulty level for this game

  srand((unsigned) time(0));

  int Player1Guess, Player2Guess, Player3Guess,Player4Guess, GuessTotal, GuessProduct;
  const int FirstCode = (rand() % difficulty) + difficulty;
  const int SecondCode = (rand() % difficulty) + difficulty;
  const int ThirdCode = (rand() % difficulty) + difficulty;
  const int FourthCode = (rand() % difficulty) + difficulty;
  const int CodeTotal = FirstCode + SecondCode + ThirdCode + FourthCode;
  const int CodeProduct = FirstCode * SecondCode * ThirdCode * FourthCode;


  std::cout << "\nEnter the four numbers " << '\n';
  std::cout << "The four numbers sum upto : " << CodeTotal << '\n';
  std::cout << "The multiple of four number is  : " << CodeProduct << '\n';

  // Guessing part of the game
  std::cout << "Enter the codes " << '\n';

  cin >> Player1Guess >> Player2Guess >> Player3Guess >> Player4Guess;

  GuessTotal = Player1Guess + Player2Guess + Player3Guess + Player4Guess;
  GuessProduct = Player1Guess *  Player2Guess * Player3Guess * Player4Guess;

  if ((GuessTotal == CodeTotal) && (GuessProduct == CodeProduct)) {

    return true;
  }
  else{
    return false;
  }
}

void game(int difficulty, int chance, bool loop){
  const int MAX_LEVEL = 5;
  PrintIntro(difficulty);
 while (loop) {
     bool bLevelComplete = PlayGame(difficulty);
     if (bLevelComplete == true) {
       difficulty++;
       if (difficulty == MAX_LEVEL) {
         std::cout << "You won !" << '\n';
         break;
       }
       else
       {
         PrintIntro(difficulty);
       }

     }else{
       chance = chance - 1;
       std::cout << "You have " << chance << " chances left \n";
       if (chance == 0) {
         std::cout << "You lose" << '\n';
         loop = false;
       }
     }
 }
}

int main() {
  int difficulty = 1;
  int chance = 5;
  bool loop = true;


  game(difficulty, chance, loop);


  return 0;
}
