
struct TCoords{
    int x,y;
};

struct TBoard{
  TCoords position,size;
  bool empty;
  char letter;
  int letterIndex;
  bool lastWord; //Guarda true si esta en la ultima palabra introducida
  int points;
  esat::SpriteHandle sprite;
};

struct TLetter{
  TCoords position,size;
  int numberCount;
  int points;
  char letter;
  esat::SpriteHandle sprite;
};

struct TPlayer{
  TCoords position[7],size;
  char name;
  int playerLetters[7];
  int playerLettersRefill[7];
  int numRandom[14];
  int numRandom2[14];
};


const int kWindowWidth=224*4+288, kWindowHeight=256*3+64;
unsigned char fps=60;
double current_time,last_time;
int fichasCounter=100, maxPlayers=2, shifts=1;
int offset=44;
int tempLetter, tempLetter2;
int coordX, coordY;
int moveLetter;

int Mposx = esat::MousePositionX();
int Mposy = esat::MousePositionY();


int availableLetters[100];
int numRandom[14];
char droppedWord[10];


  
esat::SpriteHandle g_table_sprite, g_A_sprite, g_B_sprite, g_C_sprite, g_D_sprite, g_E_sprite, g_F_sprite, 
                   g_G_sprite, g_H_sprite, g_I_sprite, g_J_sprite, g_K_sprite, g_L_sprite, g_M_sprite, 
                   g_N_sprite, g_NN_sprite, g_O_sprite, g_P_sprite, g_Q_sprite, g_R_sprite, g_S_sprite, g_T_sprite, g_U_sprite, 
                   g_V_sprite, g_W_sprite, g_X_sprite, g_Y_sprite, g_Z_sprite, g_space_sprite, g_CH_sprite, g_LL_sprite, g_RR_sprite; 

TBoard g_board[15][15];
TLetter g_letter[44];
TPlayer g_player1, g_player2;
