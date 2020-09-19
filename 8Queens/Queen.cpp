#include "Queen.h"
Queen::Queen(int size=4):available(true),boardSize(size),bias(size-1){
    this->setUpBoard();
}
void Queen::setUpBoard(){
  // All the diagonals and columns are available
  this->columns = new bool[boardSize];
  this->leftDiag = new bool[2 * boardSize - 1];
  this->rightDiag = new bool[2 * boardSize - 1];
  this->positionOnRow = new int[boardSize];
  for (int i = 0; i < boardSize; i++) {
    this->columns[i] = available;  // columns are available
    this->positionOnRow[i] = -1;   // no position set
    }
    for(int i=0;i<2*boardSize-1;i++){
        this->leftDiag[i]=available;
        this->rightDiag[i]=available;//Diagonals are available
    }
    std::cout<<"Board Initialization Done"<<std::endl;
}
void Queen::putQueen(int row){
    int col=0;
    while(col<this->boardSize){
        //Check if all diagonals and columns are available for the given col on row
        if(columns[col]==available && leftDiag[row+col]==available && rightDiag[(row-col)+bias]==available){
            columns[col]=!available;
            leftDiag[row+col]=!available;
            rightDiag[(row-col)+bias]=!available;
            positionOnRow[row] =col;
            if(row <boardSize-1){
                this->putQueen(row+1);
            //If the board reaches a roadblock i.e. cannot place a queen
            columns[col] = available;
            leftDiag[row + col] = available;
            rightDiag[(row - col) + bias] = available;
            }else{
                for(int i=0;i<boardSize;i++){
                    std::cout<<positionOnRow[i]<<std::endl;
                }
            }
        }
        col++;
    }
}