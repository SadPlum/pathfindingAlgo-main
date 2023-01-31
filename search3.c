#include <stdio.h>
#include <stdbool.h>

// declerations

    int grid[10][10] = {
        {0,0,0,3,0,0,0,0,0,0},
        {0,0,0,3,0,0,0,0,0,0},
        {0,3,0,3,3,3,3,0,0,0},
        {0,3,0,0,0,0,0,0,0,0},
        {0,3,3,3,3,3,3,3,3,3},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        } ;
    int safeGrid [10][10] ={};
    bool found = false;
    int farthestTotal=0;
    int farthestArray[10][2] = {};
    int oldTotal=1;
    int oldArray[10][2] = {};
    int start[2];
    int end[2];
    // also used to determine shortest path length, (tempCounter +1) due to expand function being called once while outside loop;
    int tempCounter = 0;
    int pathIndex = 0;
    bool pathFound = false;





// Checks if the x and y coordinates are within the 10x10 grid
bool outOfBounds(int y, int x) {
    if(y >= 0 && y < 10) {
        if(x >= 0 && x < 10) {
            return false;
        }
    }
    return true;
};

bool onPath(int next) {
    if(next == 2) {
        return true;
    }
    return false;
}

int grow(int currentY,int currentX) {
   
    if(found == true) { 
        return 0;
    };     
    // adds all the vertical and horizontal coordinates from the starting point. 
    // given a start of 9,5, the indexes array will contain {{5,8}, {4,9}, {6,9}, {5,10}}
    int indexes[4][2] = {{currentY, currentX-1}, {currentY-1, currentX}, {currentY+1, currentX}, {currentY, currentX+1}};

    for(int i=0; i< 4; i++) {
            if(found== true) {
                return 0;
            }
            int y = indexes[i][0];
            int x = indexes[i][1];
            // checks if the coordinates are within grid
            if(outOfBounds(y,x) == false){
                // If end is found, make found = true.
                if(grid[y][x]==4) {
                    printf("found");
                    found = true;
                    end[0] = y;
                    end[1] = x;
                    return 0;
                }
                //  If passable (0), grid = true.
                if(grid[y][x]== 0) {
                   grid[y][x] = 2;
                   farthestArray[farthestTotal][0] = y;
                   farthestArray[farthestTotal][1] = x;
                   farthestTotal++;
                }
        }
    } 
  
    return 0;
};

int establishRecur() {

    // Establish safe copy of grid 

  
    for(int i =0; i< 10; i++) {
        for (int j =0; j< 10; j++) {
            safeGrid[i][j] = grid[i][j];
        }
    };

    // Declare path array


   
    // FOR FUTURE
    // int* direction() {
    //     int y = start[0]; 
    //     int x = start[1];
    //     if(start[0] >= end[0]) {
    //         if(start[1] >= end[1]) {
    //             return int indexes[4][2] = {{y+1, x}, {y,x+1}, {y-1, x}, {y, x-1}};
    //         };
    //         if(start[1] <= end[1]) {
    //             return int indexes[4][2] = {{y+1, x}, {y, x-1}, {y-1, x, {y, x+1}};

    //         };
    //     };
    //     if(start[0] <= end[0]) {
    //         if(start[1] >= end[1]) {
    //             return int indexes[4][2] = {{y-1, x}, {y, x+1}, {y+1, x}, {y, x-1}};
    //         };
    //         if(start[1] <= end[1]) {
    //             return int indexes[4][2] = {{y-1, x}, {y, x-1}, {y+1, x}, {y, x+1}};
    //         };
    //     }

    //     return   int indexes[4][2] = {{y, x-1}, {y-1, x}, {y+1, x}, {y, x+1}};
    //     }
    // }

    // int path* = direction();
    int totalLength = tempCounter+1;
    int pathArray[100][2]={};

    int * array= recurse(start[0], start[1], pathIndex, totalLength, pathArray, pathFound);

    for(int i=0; i<totalLength; i++) {
        printf("%d, %d\n", array[i][0], array[i][1]);
    }

};


int * recurse(int y, int x, int pathIndex, int length, int path[100][2], bool pathFound) {
    int indexes[4][2] = {{y, x-1}, {y-1, x}, {y+1, x}, {y, x+1}};
    for(int i = 0; i < 4; i++) {
        if(pathIndex > length) {
            return 0;
        }
        int newY = indexes[i][0];
        int newX = indexes[i][1];
        if(outOfBounds(newY, newX) == true) {
            continue;
        }
        if(newY == end[0]) {
            if(newX == end[1]) {
                return path;
            }
        }
        path[pathIndex][0] = newY;
        path[pathIndex][1] = newX;
        pathIndex++;
        recurse(newY, newX, pathIndex, length, path[100][2], pathFound);

    }
    return;
};


int expand() {
    
    for(int i = 0; i < oldTotal; i++) {
        if(found == true) {
            return 0;
        };
        int y = oldArray[i][0];
        int x = oldArray[i][1];
        grow(y, x);
    }
    return 0;
}

int search(int startY, int startX) {
    while(tempCounter < 100) {
        // For first loop
        if(tempCounter == 0) {
            start[0] = startY;
            start[1] = startX;
            oldArray[0][0] = startY;
            oldArray[0][1] = startX;
            expand();
            if(found == true) {
                return 0;
            }
            tempCounter++;
        }
        // For recond loops
        else {
            oldTotal = farthestTotal;
        for(int i = 0; i < farthestTotal; i++) {
            oldArray[i][0] = farthestArray[i][0];
            oldArray[i][1] = farthestArray[i][1];
        };
        farthestTotal= 0;
        expand();
        if(found == true) {
            return 0;
        }
        tempCounter++;
        }
    }
    return 0;
};






int main() {
// 10 x 10 grid. 1 denotes start. 4 denotes end.

    // SET START
    grid[0][5] = 1;

    // SET END

    grid[0][0] = 4;


    // SEARCH ALGO

    search(0,5);
    
    printf("\ngrid:");

            for(int i=0; i<10; i++) {
                printf("\n");

                for(int j=0; j<10; j++) { 
                    if(grid[i][j] == 1) {
                        printf("S ");
                    }
                      if(grid[i][j] == 2) {
                        printf("o ");
                    }
                          if(grid[i][j] == 3) {
                        printf("X ");
                    }
                      if(grid[i][j] == 4) {
                        printf("E ");
                    }
                      if(grid[i][j] == 0) {
                        printf("  ");
                    }
                }
            }
    printf("\n\nend\n");


    // START RECURSION FOR SHORTEST PATH;
    establishRecur();

    return 0;

};

