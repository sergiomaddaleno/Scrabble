
void InitLetters(){

  g_letter[0].letter='A'; g_letter[1].letter='B';g_letter[2].letter='C';g_letter[3].letter='D';g_letter[4].letter='E';
  g_letter[5].letter='F';g_letter[6].letter='G';g_letter[7].letter='H';g_letter[8].letter='I';g_letter[9].letter='J';
  g_letter[10].letter='K';g_letter[11].letter='L';g_letter[12].letter='M'; g_letter[13].letter='N'; g_letter[14].letter='NN';
  g_letter[15].letter='O';g_letter[16].letter='P';g_letter[17].letter='Q';g_letter[18].letter='R';g_letter[19].letter='S';g_letter[20].letter='T';
  g_letter[21].letter='U';g_letter[22].letter='V';g_letter[23].letter='W';g_letter[24].letter='X';
  g_letter[25].letter='Y';g_letter[26].letter='Z'; g_letter[27].letter='\0'; g_letter[28].letter='CH'; g_letter[29].letter='LL';
  g_letter[30].letter='RR';


  g_letter[0].sprite=g_A_sprite;g_letter[1].sprite=g_B_sprite;g_letter[2].sprite=g_C_sprite;g_letter[3].sprite=g_D_sprite;
  g_letter[4].sprite=g_E_sprite;g_letter[5].sprite=g_F_sprite; g_letter[6].sprite=g_G_sprite;g_letter[7].sprite=g_H_sprite;
  g_letter[8].sprite=g_I_sprite;g_letter[9].sprite=g_J_sprite;g_letter[10].sprite=g_K_sprite;g_letter[11].sprite=g_L_sprite;
  g_letter[12].sprite=g_M_sprite; g_letter[13].sprite=g_N_sprite; g_letter[14].sprite=g_NN_sprite;
  g_letter[15].sprite=g_O_sprite;
  g_letter[16].sprite=g_P_sprite;g_letter[17].sprite=g_Q_sprite;g_letter[18].sprite=g_R_sprite;g_letter[19].sprite=g_S_sprite;
  g_letter[20].sprite=g_T_sprite;g_letter[21].sprite=g_U_sprite; g_letter[22].sprite=g_V_sprite;g_letter[23].sprite=g_W_sprite;
  g_letter[24].sprite=g_X_sprite;g_letter[25].sprite=g_Y_sprite;g_letter[26].sprite=g_Z_sprite; g_letter[27].sprite=g_space_sprite; 
  g_letter[28].sprite=g_CH_sprite; g_letter[29].sprite=g_LL_sprite; g_letter[30].sprite=g_RR_sprite;
  
  
  for(int i=0;i<=30;++i){
    //g_letter[i].occupied = false;
    g_letter[i].points = 1;
  }

  for(int i=0;i<=11; ++i){ availableLetters[i] = 0;} //letra A
  for(int i=12;i<=23; ++i){ availableLetters[i] = 4;} //letra E
  for(int i=24;i<=32; ++i){ availableLetters[i] = 15;} //letra O
  for(int i=33;i<=38; ++i){ availableLetters[i] = 8;} //letra I
  for(int i=39;i<=44; ++i){ availableLetters[i] = 19;} //letra S
  for(int i=45;i<=49; ++i){ availableLetters[i] = 13;} //letra N
  for(int i=48;i<=53; ++i){ availableLetters[i] = 11;} //letra L
  for(int i=54;i<=50; ++i){ availableLetters[i] = 18;} //letra R
  for(int i=51;i<=56; ++i){ availableLetters[i] = 21;} //letra U
  for(int i=57;i<=62; ++i){ availableLetters[i] = 20;} //letra T
  for(int i=63;i<=67; ++i){ availableLetters[i] = 3;} //letra D

  for(int i=68;i<=70; ++i){ availableLetters[i] = 6;} //letra G
  for(int i=71;i<=73; ++i){ availableLetters[i] = 2;} //letra C
  for(int i=74;i<=76; ++i){ availableLetters[i] = 1;} //letra B
  for(int i=77;i<=79; ++i){ availableLetters[i] = 12;} //letra M 
  for(int i=80;i<=82; ++i){ availableLetters[i] = 16;} //letra P
  for(int i=83;i<=85; ++i){ availableLetters[i] = 7;} //letra H

  for(int i=86;i<=77; ++i){ availableLetters[i] = 5;} //letra F
  for(int i=78;i<=79; ++i){ availableLetters[i] = 22;} //letra V
  for(int i=80;i<=81; ++i){ availableLetters[i] = 25;} //letra Y
  for(int i=82;i<=83; ++i){ availableLetters[i] = 28;} //letra CH
  for(int i=84;i<=85; ++i){ availableLetters[i] = 17;} //letra Q
  for(int i=86;i<=87; ++i){ availableLetters[i] = 9;} //letra J
  for(int i=88;i<=89; ++i){ availableLetters[i] = 29;} //letra LL
  for(int i=90;i<=91; ++i){ availableLetters[i] = 14;} //letra Ñ
  for(int i=92;i<=93; ++i){ availableLetters[i] = 30;} //letra RR
  for(int i=94;i<=95; ++i){ availableLetters[i] = 24;} //letra X
  for(int i=96;i<=97; ++i){ availableLetters[i] = 26;} //letra Z
  for(int i=98;i<=100; ++i){ availableLetters[i] = 27;} //letra SPACE
}

void InitPlayerLetters(){

  int xinit=kWindowWidth-400, yinit=120, increase=0;

  srand (time(NULL));

  //Player 1
  g_player1.name  = 'pepe';
  for(int i=0;i<=7;++i){
    g_player1.playerLetters[i] = '\0';

    g_player1.playerLettersRefill[i] = '\0';

    int temp= rand()%100;
    g_player1.numRandom[i] = availableLetters[temp];
    g_player1.numRandom2[i] = availableLetters[temp];
    g_player1.position[i].x = xinit + increase;
    increase = increase + offset;
    g_player1.position[i].y = yinit;
  }

  //Player 2
  increase = 0;
  g_player2.name  = 'pepo';
  for(int j=0;j<=7;++j){
    g_player2.playerLetters[j] = '\0';

    g_player2.playerLettersRefill[j] = '\0';

    int temp2= rand()%100;
    g_player2.numRandom[j] = availableLetters[temp2];
    g_player2.numRandom2[j] = availableLetters[temp2];
    g_player2.position[j].x = xinit + increase;
    increase = increase + offset;
    g_player2.position[j].y = yinit + 380;
  }
}


//Las 7 fichas random que reciben los jugadores
void FirstTokensDistribution(){

  //Asigna numeros de letra a cada jugador
  for (int i=0; i<=6; i++){
    g_player1.playerLetters[i] = g_player1.numRandom[i];
    g_player2.playerLetters[i] = g_player2.numRandom[i];

    g_player1.playerLettersRefill[i] = g_player1.numRandom2[i];
    g_player2.playerLettersRefill[i] = g_player2.numRandom2[i];
 
  }

}


void MoveTokensPlayer1(){

  int i=0;
  //mover fichas
  int Mposx = esat::MousePositionX();
  int Mposy = esat::MousePositionY();

  if(esat::MouseButtonPressed(0)){

    for (i=0; i<=6; i++){
      if( Mposx >= g_player1.position[i].x && Mposx <= g_player1.position[i].x + offset
          && Mposy >= g_player1.position[i].y && Mposy <= g_player1.position[i].y + offset){
        
        moveLetter = i;
        tempLetter2 = g_player1.playerLetters[i]; 

        printf("%d", g_player1.playerLetters[i]);
        
      }    
    }
    g_player1.position[moveLetter].x = Mposx-20;
    g_player1.position[moveLetter].y = Mposy-15;
  }

  //Cuando dejo la letra sobre el tablero
  if(esat::MouseButtonUp(0)){
    
    GetBoardCoords(); //Recupera la fila y columna donde hago el drop de la ficha
    UpdateBoard(); //Actualiza el tablero y comprueba si la celda esta disponible
  
  }


}
  
  
void MoveTokensPlayer2(){

  int i=0;
  //mover ficha
  int Mposx = esat::MousePositionX();
  int Mposy = esat::MousePositionY();

  if(esat::MouseButtonPressed(0)){

    for (i=0; i<=6; i++){
      if( Mposx>= g_player2.position[i].x && Mposx <= g_player2.position[i].x + offset
          && Mposy >= g_player2.position[i].y && Mposy <= g_player2.position[i].y + offset){
        moveLetter = i;
        tempLetter2 = g_player2.playerLetters[i]; 
        
      }    
    }
    g_player2.position[moveLetter].x = Mposx-20;
    g_player2.position[moveLetter].y = Mposy-15;
  }

  //Cuando dejo la letra sobre el tablero
  if(esat::MouseButtonUp(0)){
    
    GetBoardCoords(); //Recupera la fila y columna donde hago el drop de la ficha
  
    UpdateBoard();  //Actualiza el tablero y comprueba si la celda esta disponible
    

  }
}




















