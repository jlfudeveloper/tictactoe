#include <iostream>
#include <cmath>

using namespace std;
//initialize all functions
bool legalMove(char board[3][3], char marker[2]);
bool checkWin(char board[3][3]);
bool checkTie(char board[3][3]);
void placeMarker(char (&board)[3][3], char marker[2], bool turn);
void printBoard(char board[3][3]);
void clearBoard(char (&board)[3][3]);

int main(){
  
  char board[3][3]; //tictactoe board
  char move[3]; //for player input
  bool p1turn = true; //who's turn it is
  bool gameOver = false; //if it is a tie orwin
  clearBoard(board); //initialize board
  cout << "welcome to tictactoe! input your moves in the format A0, B1, etc." << endl;
  printBoard(board);
  while(true){ //game loop
    while(true){ //input loop
      cout << "input your move: " << endl;
      cin.get(move,3);
      cin.get();
      if(legalMove(board, move)){
	break; //if it is a legal move, we don't have to keep prompting
      }
    }
    if(legalMove(board, move)){
      placeMarker(board, move, p1turn); //place the marker
      p1turn = !p1turn; //change the turn
      printBoard(board); //print the board
    }
    //checks for wins and ties
    if(checkWin(board) && p1turn){ 
       cout << "player 2 wins!" << endl;
       gameOver = true;
     }
    else if(checkWin(board)){ 
       cout << "player 1 wins!" << endl;
       gameOver = true;
     }
    else if(checkTie(board)){
      cout << "tie!" << endl;
      gameOver = true;
    }
    //if win or tie, prompts the user for play again
    if(gameOver){
      char playAgain[2];
      cout << "play again? (y/n)" << endl;
      cin.get(playAgain, 2);
      cin.get();
      if(playAgain[0] == 'y'){
	clearBoard(board);
	printBoard(board);
	p1turn = true;
	gameOver = false;
      }
      else if(playAgain[0] == 'n'){
	cout << "bye." << endl;
	return 0;
      }
      else{
	cout << "response not recognized!" << endl;
	return 0;
      }
    }
  }
  return 0; 
}
//checks for ties
bool checkTie(char board[3][3]){
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      if(board[a][b] == ' '){
	return false;
      }
    }
  }
  return true;
}
//checks if something is a legal move (space taken or illegal input)
bool legalMove(char board[3][3], char marker[2]){
  if((int)marker[1] >= 48 && (int)marker[1] <= 50){
    if((int)marker[0] >= 65 && (int)marker[0] <= 67){
      int x = int(marker[0])-65;
      int y = int(marker[1])-48;
      if(board[y][x] == ' '){
	return true;
      }
    }
  }
  cout << "invalid move or space taken! please input in form A1!" << endl;
  return false;
}
//checks for wins
bool checkWin(char board[3][3]){
  //horizontal
  for(int a = 0; a < 3; a++){
    if(board[a][0] == board[a][1] && board[a][1] == board[a][2] && board[a][0] != ' '){
      return true;
    }
  }
  //vertical
  for(int a = 0; a < 3; a++){
    if(board[0][a] == board[1][a] && board[1][a] == board[2][a] && board[0][a] != ' '){
      return true;
    }
  }
  //diagonols
  int diagonolWin = 0;
  char player;
  for(int i = 0; i < 2; i++){
    if(i == 0){
      player = 'X';
    }
    else{
      diagonolWin = 0;
      player = 'O';
    }
    for(int a = 0; a < 3; a++){
      if(board[a][a] == player){
	diagonolWin++;
      }
    }
    if(diagonolWin == 3){
      return true;
    }
  }
  diagonolWin = 0;
  for(int i = 0; i < 2; i++){
    if(i == 0){
      player = 'X';
    }
    else{
      diagonolWin = 0;
      player = 'O';
    }
    for(int a= 0; a < 3; a++){
       if(board[a][abs(a-2)] == player){
	 diagonolWin++;
       }
    }
    if(diagonolWin == 3){
      return true;
    }
  }
  return false; 
}
//places the marker at the desired space
void placeMarker(char (&board)[3][3], char marker[3], bool p1turn){
  //places a marker in the spot
  int x = int(marker[0])-65;
  int y = int(marker[1])- 48;
  if(p1turn){
    board[y][x] = 'X';
  }
  else{
    board[y][x] = 'O';
  }
}
//prints the tictactoe board out
void printBoard(char board[3][3]){
  char line[5];
  line[4] = '\0';
  cout << " ABC" << endl;
  for(int a = 0; a < 3; a++){
    line[0] = char(a+48);
    for(int b = 0; b < 3; b++){
      line[b+1] = board[a][b];
    }
    cout << line << endl;
  }
}
void clearBoard(char (&board)[3][3]){
  for(int a = 0; a < 3; a ++){
    for(int b = 0; b < 3; b++){
      board[b][a] = ' ';
    }
  }
}
