#include <stdio.h>
#include <stdbool.h>

// declerations

    int starty = 6;
    int startx = 5;
    int grid[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,4,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        } ;
    bool found = false;
    int farthestArrayIndex=0;
    int farthestArray[][2] = {};
    int oldIndex=0;
    int oldArray[][2] = {};




// Checks if the x and y coordinates are within the 10x10 grid
bool outOfBounds(int y, int x) {
    if(y >= 0 && y < 10) {
        if(x >= 0 && x < 10) {
            return false;
        }
    }
    return true;
};

int grow(int currentY,int currentX) {
    printf("START Y: %d, X: %d\n", currentY, currentX);
    if(found == true) { 
        return 0;
    };     
    // adds all the vertical and horizontal coordinates from the starting point. 
    // given a start of 9,5, the indexes array will contain {{5,8}, {4,9}, {6,9}, {5,10}}
    int indexes[4][2] = {{currentY, currentX-1}, {currentY-1, currentX}, {currentY+1, currentX}, {currentY, currentX+1}};
    for(int i=0; i< 4; i++) {
            int y = indexes[i][0];
            int x = indexes[i][1];
            // checks if the coordinates are within grid
            if(outOfBounds(y,x) == false){
                // If end is found, make found = true.
                if(grid[y][x]==4) {
                    printf("found");
                    found = true;
                    return 0;
                }
                //  If passable (0), grid = true.
                if(grid[y][x]== 0) {
                   grid[y][x] = 2;
                   farthestArray[farthestArrayIndex][0] = y;
                   farthestArray[farthestArrayIndex][1] = x;
                   farthestArrayIndex++;
                }
        }
    } 
  
    return 0;
};


int expand() {
    int max = oldIndex +1;
    for(int i = 0; i < max; i++) {
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
    oldArray[0][0] = startY;
    oldArray[0][1] = startX;
    expand();
  printf("Y: %d X: %d\n", farthestArray[0][0], farthestArray[0][1]);
  printf("Y: %d X: %d\n", farthestArray[1][0], farthestArray[1][1]);
  printf("Y: %d X: %d\n", farthestArray[2][0], farthestArray[2][1]);

    printf("old array\n");
    for(int i=0; i<oldIndex; i++) {
      printf("Y: %d X: %d\n", oldArray[i][0], oldArray[i][1]);
    }

    // while(tempcounter < 1) {
    //     // for(int i = 0; i < farthestArrayIndex; i++) {
    //     //  printf("array index of  %d, %d - %d \n", farthestArrayIndex, farthestArray[i][0], farthestArray[i][1]);
    //     // };

    //     oldIndex = farthestArrayIndex;
        
    //     for(int i = 0; i < farthestArrayIndex; i++) {
    //         oldArray[i][0] = farthestArray[i][0];
    //         oldArray[i][1] = farthestArray[i][1];
    //     };

    //     expand();
    //     farthestArrayIndex= 0;
    //     tempcounter++;
    // }
    return 0;
};





int main() {
// 10 x 10 grid. 1 denotes start. 4 denotes end.


  
  
    search(9,5);
    
          printf("\ngrid:");
                    for(int i=0; i<10; i++) {
                        printf("\n");
                        for(int j=0; j<10; j++) { 
                            printf("%d", grid[i][j]);
                        }
                    }
            printf("\n\nend\n");
    return 0;

};




    // for(int i = 0; i < farthestArrayIndex; i++) {
    //     printf("\nbefore loop\n");
    //     printf("FARTHEST Y: %d X: %d\n", farthestArray[i][0], farthestArray[i][1]);
    //     printf("OLD Y: %d X: %d\n", oldArray[i][0], oldArray[i][1]);
    //     oldArray[i][0] = farthestArray[i][0];
    //     oldArray[i][1] = farthestArray[i][1];
    //     printf("\nafter loop\n");
    //     printf("\ni = %d\n", i);
    //     printf("FARTHEST Y: %d X: %d\n", farthestArray[i][0], farthestArray[i][1]);
        
    //     printf("OLD Y: %d X: %d\n", oldArray[i][0], oldArray[i][1]);

    // };
