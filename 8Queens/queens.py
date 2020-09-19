
class Board():
    def __init__(self,size=4):
        self.size=size
        self.isAvailable=True
        self.columns = [self.isAvailable]*self.size
        self.rightDiagonal = [self.isAvailable]*(2*self.size-1)
        self.leftDiagonal = [self.isAvailable]*(2*self.size-1)
        self.finalPositions = [-1]*self.size
        self.bias = self.size-1
    def placeQueen(self,row):
        col = 0 
        while col<self.size:
            if self.columns[col] is self.isAvailable and self.leftDiagonal[row+col] is self.isAvailable and self.rightDiagonal[row-col+self.bias] is self.isAvailable:
                self.columns[col]= not self.isAvailable
                self.leftDiagonal[row+col]= not self.isAvailable
                self.rightDiagonal[row-col+self.bias]=not self.isAvailable
                self.finalPositions[row]=col
                if row<self.size-1:
                    self.placeQueen(row+1)
                    if self.finalPositions[-1]==-1:
                        self.columns[col]= self.isAvailable
                        self.leftDiagonal[row+col]= self.isAvailable
                        self.rightDiagonal[row-col+self.bias]=self.isAvailable
                        self.finalPositions[row]=-1
                else:
                    return  

            col+=1
        return self.finalPositions

        

if __name__ == "__main__":
    b = Board(16)
    print(b.placeQueen(0))
