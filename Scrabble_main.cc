#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "resources/include/scrabble_variables.cc"
#include "resources/include/scrabble_sprites.cc"
#include "resources/include/scrabble_board.cc"
#include "resources/include/scrabble_letters.cc"
#include "resources/include/scrabble_interface.cc"


void Game(){
 
  DrawBoard();
  DrawPlayers();

  if (shifts==1){ //Jugada inicial
    
    FirstTokensDistribution();
  }

  if (shifts%2 == 1){ //Turno del jugador 1
    MoveTokensPlayer1();

    if (esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
      ValidateWord();
      shifts++;
    }
      //calculatePoints(player);
  }

  if (shifts%2 == 0){ //Turo del jugador 2
   MoveTokensPlayer2();

    if (esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
      ValidateWord();
      shifts++;
    }
     //calculatePoints(player);
  }

  ValidateWord();
}

void InitParts(){

  InitSprites();
  InitBoard();
  InitLetters();
  InitPlayers();
  InitPlayerLetters();

}


int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindowWidth,kWindowHeight);
  WindowSetMouseVisibility(true);

  InitParts();

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

  	last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(71,125,110);
   
    Game();
    esat::DrawEnd();

   do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
   esat::WindowFrame();
  }

  ReleaseSprites();
  esat::WindowDestroy();

  return 0;
}

