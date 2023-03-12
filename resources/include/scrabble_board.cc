
void InitBoard(){

  int table_width=768, table_height=737, xinit=54, yinit=84, offset=44;

  for(int i=0;i<=15;++i){ 
    for(int j=0;j<=15;++j){ 

      g_board[i][j].position.x = xinit + i * offset;
      g_board[i][j].position.y = yinit + j * offset;
      g_board[i][j].size.x = table_width;
      g_board[i][j].size.y = table_height;
      g_board[i][j].empty = true;
      g_board[i][j].letterIndex = '\0';
      g_board[i][j].lastWord = false;
      g_board[i][j].points  = 0;

      g_board[i][j].sprite = g_table_sprite;

    }
  } 
}

void DrawBoard(){

  esat::DrawSprite(g_table_sprite, 0, 45); 
    
}

void GetBoardCoords(){

  Mposx = esat::MousePositionX();
  Mposy = esat::MousePositionY();
  
  for (int i=1; i<=15; i++){
      for (int j=1; j<=15; j++){


        if(Mposx >= g_board[i][j].position.x && Mposx <= g_board[i][j].position.x + 50 && 
           Mposy >= g_board[i][j].position.y && Mposy <= g_board[i][j].position.y + 50){
            
          coordX = i+1;
          coordY = j+1;
        }
      }
  }
  //printf("%d ", coordX);   
  //printf("%d\n", coordY);   
}


void UpdateBoard(){

    if (g_board[coordX][coordY].empty){ //Cuando la celda esta disponible

      g_board[coordX][coordY].letterIndex = tempLetter2;
      g_board[coordX][coordY].empty = false;

      g_board[coordX][coordY].lastWord = true;


    }else{ //Cuando la celda esta ocupada por otra

        esat::DrawSetFillColor(139,0,0);
        esat::DrawText(kWindowWidth-400, kWindowHeight/2, "Ocuppied Cell");

    }  


}

bool ValidateWord(){

	int countLetter = 0;
	int tempLetterNumb = 0;
	char tempLetterChar = '\0';
	bool validCell; 
	
	
	//Validar que la primera palabra está sobre el centro del tablero
	if (shifts%2 == 1 && g_board[8][8].lastWord == false){
    esat::DrawSetFillColor(225,0,0);
		esat::DrawText(350, 35, "word must start at center");
		return false;
	}	
	
	//Cuando no es la primera jugada, compruaba que alrededor de la palabra metida hay alguna celda ocupada 
	if (shifts > 1) {

		validCell = false;

		for (int i=1; i<=15; i++){
			for (int j=1; j<=15; j++){

				if (g_board[i][j].lastWord == true){ // Para cada celda donde se ha dejado una letra

					if ((g_board[i-1][j].letterIndex >= 0) || (g_board[i+1][j].letterIndex >= 0) || 
					   (g_board[i][j-1].letterIndex >= 0) || (g_board[i+1][j].letterIndex >= 0)){  

						validCell = true;
					}
				}
			}		
		}

		if (validCell == false) {
			return false;
		} else {return true;}

	}
	
	//Mete en el array droppedword la última palabra que se ha escrito en el tablero
	memset(droppedWord ,' ',10);
	for (int i=1; i<=15; i++){
      for (int j=1; j<=15; j++){
		if (g_board[i][j].lastWord == true) { //Cuando el player ha metido una letra de la última palabra
			
			tempLetterNumb= g_board[i][j].letterIndex;
			tempLetterChar = g_letter[tempLetterNumb].letter;
			droppedWord[countLetter]=g_board[i][j].letter;
		}
	  }
	}
	//printf("%s", droppedWord);
	
}
