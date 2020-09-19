#include "Queen.h"
int main(int argc, char** argv){
    int rows;   
    if(argc<2){
        rows = 4;
    }else{
        rows = atoi(argv[1]);
    }
    std::cout<<"Building a chessboard of size "<<rows<<"x"<<rows<<std::endl;
    Queen q = Queen(rows);
    q.putQueen(0);
}
