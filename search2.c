#include <stdio.h>
#include <stdbool.h>

// declerations

bool outOfBounds(int, int);
int grow(int[10][10], int, int, bool, int[][2], int);






// Checks if the x and y coordinates are within the 10x10 grid
bool outOfBounds(int y, int x) {
    if(y >= 0 && y < 10) {
        if(x >= 0 && x < 10) {
            return false;
        }
    }
    return true;
};

int grow(int grid[10][10], int currentY,int currentX, bool found, int farthestArray[][2], int farthestArrayIndex) {
    if(found == true) { 
        return ;
    };     
     // adds count to loop over elements in array
    int indexCounter =0;
    // adds all the vertical and horizontal coordinates from the starting point. 
    // given a start of 9,5, the indexes array will contain {{5,8}, {4,9}, {6,9}, {5,10}}
    int indexes[4][2] = {{currentY, currentX-1}, {currentY-1, currentX}, {currentY+1, currentX}, {currentY, currentX+1}};
    for( int i=0; i< 4; i++) {
            int y = indexes[i][0];
            int x = indexes[i][1];
            // checks if the coordinates are within grid
            if(outOfBounds(y,x) == false){
                // If end is found, make found = true.
                if(grid[y][x]==4) {
                    printf("found");
                    found = true;
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
};


int expand(int grid[10][10], bool found, int oldArray[][2], int oldIndex, int newArray[][2], int newIndex) {
    int max = oldIndex +1;
    for(int i = 0; i < max; i++) {
        int y = oldArray[i][0];
        int x = oldArray[i][1];
        grow(grid, y, x, found, newArray, newIndex);
    }
}

int search(int grid[10][10], bool found, int startY, int startX) {
    int firstArray[] = {{startY, startX-1}, {startY-1, startX}, {startY+1, startX}, {startY, startX+1}};

    int farthestArray[][2]={};
    int farthestArrayIndex = 0;

    while(found == false) {
        
       int farthestArray[][2]={};
       int farthestArrayIndex = 0;
    }
};





int main() {
// 10 x 10 grid. 1 denotes start. 2 denotes end.
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
    printf("the strarting point, %d, axis' are\nx=%d & y=%d\n", grid[starty][startx], startx, starty);
    printf("%d", grid[6][5]);
    makeSearchArr(grid, 9,5, found);
    
          printf("\ngrid:");
                    for(int i=0; i<10; i++) {
                        printf("\n");
                        for(int j=0; j<10; j++) { 
                            printf("%d", grid[i][j]);
                        }
                    }

    return 0;

};