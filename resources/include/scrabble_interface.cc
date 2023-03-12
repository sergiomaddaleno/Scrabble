
void InitPlayers(){

    char cadena[10];

    esat::DrawSetTextFont("./resources/font/Scrabble.ttf");
    esat::DrawSetTextSize(40.0f);

}

void DrawPlayers(){
  
   char cadena[10];
   int i=0;
   itoa(i,cadena,10);
   
   esat::DrawSetFillColor(0,0,0);
   esat::DrawText(kWindowWidth-400, 96, "Player 1:");


   for (int i=0; i<=6; i++){ //Sprites fichas jugador 1
    tempLetter = g_player1.playerLetters[i];
    esat::DrawSprite(g_letter[tempLetter].sprite,  g_player1.position[i].x, g_player1.position[i].y);
   }

   esat::DrawSetFillColor(0,0,0);
   esat::DrawText(kWindowWidth-400, 480, "Player 2:");
   
   for (int i=0; i<=6; i++){ //Sprites fichas jugador 2
    tempLetter = g_player2.playerLetters[i];
    esat::DrawSprite(g_letter[tempLetter].sprite,  g_player2.position[i].x, g_player2.position[i].y); 
   }

   //Turno de cada jugador
    if (shifts%2 == 1){
        char cadena[10];
        int i=0;
        itoa(i,cadena,10);
   
        esat::DrawSetFillColor(225,255,255);
        esat::DrawText(kWindowWidth-400, kWindowHeight-500, "move & Press Enter");
        esat::DrawText(kWindowWidth-400, kWindowHeight-450, "-------------------------");
    }

    if (shifts%2 == 0){
        char cadena[10];
        int i=0;
        itoa(i,cadena,10);
   
        esat::DrawSetFillColor(255,255,255);
        esat::DrawText(kWindowWidth-400, kWindowHeight-90, "move & Press Space");
        esat::DrawText(kWindowWidth-400, kWindowHeight-40, "-------------------------");
    }

}



