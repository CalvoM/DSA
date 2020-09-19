#ifndef QUEEN_H_
#define QUEEN_H_
#include <iostream>
class Queen{
    public:
        Queen(int size);
        void putQueen(int startingRow);
    private:
        bool* columns,*leftDiag,*rightDiag;
        const bool available;
        int boardSize;
        int bias;
        int* positionOnRow;
        void setUpBoard();
};
#endif