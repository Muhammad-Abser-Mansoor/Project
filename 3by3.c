#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Checking columns and rows to see if any column or row collinear to the coordinates has a number equal to the inputted number
int checkRowsColumns(int ar[][9],int randposr,int randposc,int num) {
    for (int k = 0;k<9;k++) { 
        if (num == ar[randposr][k] || num == ar[k][randposc]) {
          return 0; 
        }
    }
    return 1;
}

int checkSubblock(int ar[][9],int randposr,int randposc,int num) {
    int srow = 3 * (randposr / 3);
    int scolumn = 3 * (randposc / 3);
    for (int k = srow;k<srow + 3;k++) { // Now check the 3x3 subblock that the address belongs to and find if any equal value exists
        for (int j = scolumn;j<scolumn + 3;j++) {
            if (num == ar[k][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int checkingcondition(char arr[][12], int row, int col) {
    int check;
    arr[row][col];
    bool flag = true;

    // checking Row and Column
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            check = arr[i][j];

            // Check Row
            for (int k = j + 1; k < col; k++) {
                if (check != 0 && check == arr[i][k]) {
                    flag = false;
                }
            }

            // Check Column
            for (int k = i + 1; k < row; k++) {
                if (check != 0 && check == arr[k][j]) {
                    flag = false;
                }
            }
        }
    }
    
    // checking sub blocks for easy level
    if (row == 6 && col == 6) {
        for (int startRow = 0; startRow < row; startRow += 2) {
            for (int startCol = 0; startCol < col; startCol += 3) {
                int subBlock[10] = {0};  

                for (int i = startRow; i < startRow + 2; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        check = arr[i][j];

                        if (check != 0) {
                            if (subBlock[check] == 1) {
                                flag = false;  
                                return flag;
                            } else {
                                subBlock[check] = 1;  
                            }
                        }
                    }
                }
            }
        }
    }
    // checking sub blocks for mid level
    if (row == 9 && col == 9) {
        for (int startRow = 0; startRow < row; startRow += 3) {
            for (int startCol = 0; startCol < col; startCol += 3) {
                int subBlock[10] = {0};  

                for (int i = startRow; i < startRow + 3; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        check = arr[i][j];

                        if (check != 0) {
                            if (subBlock[check] == 1) {
                                flag = false;  
                                return flag;
                            } else {
                                subBlock[check] = 1;  
                            }
                        }
                    }
                }
            }
        }
    }
  // Checking sub-block for hard level
if (row == 12 && col == 12) {
    for (int startRow = 0; startRow < row; startRow += 3) {
        for (int startCol = 0; startCol < col; startCol += 4) {
            int subBlock[12] = {0};

            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 4; j++) {
                    check = arr[i][j];

                    if (check != '0') {
                        int index;
                        if (check >= '0' && check <= '9') {
                            index = check - '0' - 1;  // Adjust index for 0-based array
                        } else if (check >= 'a' && check <= 'c') {
                            index = check - 'a' + 9;  // Adjust index for 0-based array
                        } else {
                            flag = false;
                            return flag;
                        }
                        if (subBlock[index] == 1) {
                            flag = false;
                            return flag;
                        } else {
                            subBlock[index] = 1;
                        }
                    }
                }
            }
        }
    }
}

    return flag;
}

void inputOutput(int arr[][9], int all_rows[22], int all_cols[22]){

    bool isSuccessful = false, notAllZero = true;
    int i = 0;

    while(!isSuccessful){

        start : ;

        char choice;

        if(i > 0){
            do {
                printf("Do you want to replace any value or want to add any value (press r to replace or a to add) : ");
                scanf(" %c", &choice);
            } while (choice != 'a' && choice != 'r');
        } else {
            choice = 'a';
        }

        switch(choice){

            int rn, cn;

            case 'a' : 
            label_a : ;

                do {
                    printf("Enter the row number and column number in which you want to add the value (in format row-column) : ");
                    scanf("%d-%d", &rn, &cn);
                    
                    if(rn < 1 || rn > 9 || cn < 1 || cn > 9){
                        printf("Your entered row no. or column no. or both does not exist.\n");
                    }
                } while(rn < 1 || rn > 9 || cn < 1 || cn > 9);    

                if(!arr[rn-1][cn-1]){
                    int value;
                    do{
                        printf("Enter the value you want to add at row no %d, column no. %d from (1-9) : ", rn, cn);
                        scanf("%d", &value);

                        if(value < 1 || value > 9){
                            printf("You have entered the wrong value that does not belong to the range (1-9)");
                        }
                    } while(value < 1 || value > 9);
                    if(checkRowsColumns(arr, rn-1, cn-1, value) && checkSubblock(arr, rn-1, cn-1, value)){
                        arr[rn-1][cn-1] = value;
                        i++;
                    } else{
                        printf("There is already same value exist in that row, column or subblock. Please try again.\n");
                        goto start;
                    }
                } else {

                    char pref;
                    
                    if(i > 0){
                        do {
                            printf("There is already a value exist at row no. %d, column %d. If you want to replace that value, press 'r' or otherwise press 'a' again to choose another row and column to add the value : ", rn, cn);
                            scanf(" %c", &pref);
                        } while(pref != 'a' && pref != 'r');
                    } else {
                        printf("There is already a value exist.Please try again.\n");
                        goto label_a;
                    }
                    
                    if(pref == 'r'){
                        goto label_r;
                    } else {
                        goto label_a;
                    }
                }
                break;

            case 'r' : 
            label_r : ;

                bool isCoordinateSame = false;

                do {
                    printf("Enter the row no. and column no. in which you want to replace the value (in format row-column) : ");
                    scanf("%d-%d", &rn, &cn);
                    
                    if(rn < 1 || rn > 9 || cn < 1 || cn > 9){
                        printf("Your entered row no. or column no. or both does not exist.\n");
                    } else {
                        for(int i = 0; i < 22; i++){
                            if(rn-1 == all_rows[i] && cn-1 == all_cols[i]){
                                printf("You cant replace the value at row no. %d, column no. %d as the value there is computer generated.Please try again.\n", rn, cn);
                                isCoordinateSame = true;
                                goto start;
                            }
                        }
                    }
                } while(rn < 1 || rn > 9 || cn < 1 || cn > 9 || isCoordinateSame);

                if(arr[rn-1][cn-1]){
                    int value;
                    do{
                        printf("Enter the new value from which you want want to replace the value at row no %d, column no. %d from (1-9) : ", rn, cn);
                        scanf("%d", &value);
                    } while(value < 1 || value > 9);
                    if(checkRowsColumns(arr, rn-1, cn-1, value) && checkSubblock(arr, rn-1, cn-1, value)){
                        arr[rn-1][cn-1] = value;
                    } else{
                        printf("There is already same value exist in that row, column or subblock. Please try again.\n");
                        goto start;
                    }
                } else {

                    char pref;
                    
                    do {
                        printf("There is not any value exist at row no. %d, column no. %d. If you want to add their a value, press 'a' or otherwise press 'r' again to choose another row and column to replace that value : ", rn, cn);
                        scanf(" %c", &pref);
                    } while(pref != 'a' && pref != 'r');
                    
                    if(pref == 'r'){
                        goto label_r;
                    } else {
                        goto label_a;
                    }
                }

                break;
        }

        printf("\n");
        for (int i = 0;i<9;i++) { // Printing the initial matrix
            if(!(i % 3)){
                printf("  - - -   - - -   - - -\n");
            }
            for (int j = 0;j<9;j++) {
                if(!(j % 3)){
                    printf("| ");
                }
                (arr[i][j]) ? printf("%d ",arr[i][j]) : printf("  "), notAllZero = false; 
                if(j+1==9){
                    printf("| ");
                }
            }
            printf("\n");
            if(i+1==9){
                printf("  - - -   - - -   - - -\n");
            }
        }
        printf("\n");

        if(checkingcondition(arr, 9, 9) && notAllZero){
            printf("Congratulations. You win the game.");
            isSuccessful = true;
        }
    }
}

void createMatrixMD() {
    int ar[9][9] = {0}; // Creating a Sudoku Matrix (Medium Difficullty)
    int all_rows[22], all_cols[22];
    int clue = 0;
    int num = 0;
    srand(time(NULL));
    for (int i = 0, k = 0;clue < 22;i++) { // Loop for inserting 22 clues within the empty matrix
        
        int randposr = (rand() % (9));

        int randposc = (rand() % (9)); // random numbers chosen to randomly select any block and insert a clue
        
        if (ar[randposr][randposc] == 0) { // Checks if there is no clue present

            num = (rand() % (9)) + 1; // Inputs a random number between 1 and 9 into num variable
           
            if (checkRowsColumns(ar,randposr,randposc,num) == 1 && checkSubblock(ar,randposr,randposc,num) == 1) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }
    
    for (int i = 0;i<9;i++) { // Printing the initial matrix
        if(!(i % 3)){
            printf("  - - -   - - -   - - -\n");
        }
        for (int j = 0;j<9;j++) {
            if(!(j % 3)){
                printf("| ");
            }
            (ar[i][j]) ? printf("%d ",ar[i][j]) : printf("  ");
            if(j+1==9){
                printf("| ");
            }
        }
        printf("\n");
        if(i+1==9){
            printf("  - - -   - - -   - - -\n");
        }
    }
    
    inputOutput(ar, all_rows, all_cols);
}

void main() {
    createMatrixMD();
}
