#include<stdio.h>
// #define BOARD_SIZE 5
int n;

void input(){
    printf("Enter the value of n: ");
    scanf("%d", &n);
}
void displayChess(int chBoard[n][n]) {
   for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++)
         printf("%d ", chBoard[row][col]);
      printf("\n");
   }
}
int isQueenPlaceValid(int chBoard[n][n], int crntRow, int crntCol) {
   // checking if queen is in the left or not    
   for (int i = 0; i < crntCol; i++)    
      if (chBoard[crntRow][i])
         return 0;
   for (int i = crntRow, j = crntCol; i >= 0 && j >= 0; i--, j--)
      //checking if queen is in the left upper diagonal or not
      if (chBoard[i][j])       
         return 0;
   for (int i = crntRow, j = crntCol; j >= 0 && i < n; i++, j--)
      //checking if queen is in the left lower diagonal or not
      if (chBoard[i][j])      
         return 0;
   return 1;
}
int solveProblem(int chBoard[n][n], int crntCol) {
   //when N queens are placed successfully
   if (crntCol >= n)           
      return 1;
   // checking placement of queen is possible or not
   for (int i = 0; i < n; i++) {     
      if (isQueenPlaceValid(chBoard, i, crntCol)) {
         //if validate, place the queen at place (i, col)
         chBoard[i][crntCol] = 1;     
         //Go for the other columns recursively
         if (solveProblem(chBoard, crntCol + 1))    
            return 1;          
         //When no place is vacant remove that queen   
         chBoard[i][crntCol] = 0;        
      }
   }
   return 0;      
}
int displaySolution() {
   int chBoard[n][n];
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         //set all elements to 0
         chBoard[i][j] = 0;      
   //starting from 0th column
   if (solveProblem(chBoard, 0) == 0) {     
      printf("Solution does not exist");
      return 0;
   }
   displayChess(chBoard);
   return 1;
}
int main() {
    input();
   displaySolution();
   return 0;
}