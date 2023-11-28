#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void createMatrixED();
void createMatrixMD();
void createMatrixHD();
void inputOutput(int all_rows[], int all_cols[], int totalRows, int totalClues, char arr[totalRows][totalRows], int sr, int sc);
int checkRowsColumns(int randposr,int randposc,int num, int length, char ar[length][length]);
int checkSubblock(int randposr,int randposc,int num, int length, int sr, int sc, char ar[length][length]);
void printMatrix(int totalRows, int sr, int sc, char arr[totalRows][totalRows]);
int checkingForEasy(char arr[][6], int row, int col);
int checkingForMedium(char arr[][9], int row, int col);
int checkingForHard(char arr[][12], int row, int col);

void main() {

    srand(time(NULL));

    char difficultyLevel;

    do {
        printf("Enter the difficulty level for which you want to play (press E for easy, M for medium or H for hard): ");
        scanf(" %c", &difficultyLevel);
        getchar();

        if(difficultyLevel != 'E' && difficultyLevel != 'M' && difficultyLevel != 'H'){
            printf("Please choose the correct option from 'E', 'M' or 'H'\n");
        }
    } while(difficultyLevel != 'E' && difficultyLevel != 'M' && difficultyLevel != 'H');

    switch(difficultyLevel){

        case 'E' : 
            createMatrixED();
            break;
        case 'M' : 
            createMatrixMD();
            break;
        case 'H' :
            createMatrixHD();
            break;
    }
}

void createMatrixED() {
    char ar[6][6] = {0}; // Creating a Sudoku Matrix (Easy Difficullty)
    int all_rows[14], all_cols[14];
    int clue = 0;
    int num = 0;
    for (int i = 0, k = 0;clue < 14;i++) { // Loop for inserting 14 clues within the empty matrix
        
        int randposr = (rand() % (6));

        int randposc = (rand() % (6)); // random numbers chosen to randomly select any block and insert a clue
        
        if (!ar[randposr][randposc]) { // Checks if there is no clue present

            num = (rand() % (6)) + 1; // Inputs a random number between 1 and 6 into num variable
           // If statement checks the functions return values to see if num passes the sudoku rules
            if (checkRowsColumns(randposr, randposc, num, 6, ar) && checkSubblock(randposr,randposc,num,6,2,3, ar)) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }

    printMatrix(6, 2, 3, ar);
    inputOutput(all_rows, all_cols, 6, 14, ar, 2, 3);
}

void createMatrixMD() {
    char ar[9][9] = {0}; // Creating a Sudoku Matrix (Medium Difficullty)
    int all_rows[22], all_cols[22];
    int clue = 0;
    int num = 0;
    for (int i = 0, k = 0;clue < 22;i++) { // Loop for inserting 22 clues within the empty matrix
        
        int randposr = (rand() % (9));

        int randposc = (rand() % (9)); // random numbers chosen to randomly select any block and insert a clue
        
        if (!ar[randposr][randposc]) { // Checks if there is no clue present

            num = (rand() % (9)) + 1; // Inputs a random number between 1 and 9 into num variable
           
            if (checkRowsColumns(randposr,randposc,num, 9, ar) && checkSubblock(randposr,randposc,num, 9, 3, 3, ar)) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }

    printMatrix(9, 3, 3, ar);
    inputOutput(all_rows, all_cols, 9, 22, ar, 3, 3);
}

void createMatrixHD() {
    char ar[12][12] = {0}; // Creating a Sudoku Matrix (Hard Difficullty)
    int all_rows[37], all_cols[37];
    int clue = 0;
    int num = 0;
    for (int i = 0, k = 0; clue < 37; i++) { // Loop for inserting 37 clues within the empty matrix
        
        int randposr = (rand() % (12));

        int randposc = (rand() % (12)); // random numbers chosen to randomly select any block and insert a clue
        
        if (!ar[randposr][randposc]) { // Checks if there is no clue present

            num = (rand() % (12)) + 1; // Inputs a random number between 1 and 12 into num variable
            // If statement checks the functions return values to see if num passes the sudoku rules
            if (checkRowsColumns(randposr, randposc, num, 12, ar) && checkSubblock(randposr,randposc,num,12,3,4,ar)) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }
    
    printMatrix(12, 3, 4, ar);
    inputOutput(all_rows, all_cols, 12, 37, ar, 3, 4);
}

// Function to handle input and output for the game
void inputOutput(int all_rows[], int all_cols[], int totalRows, int totalClues, char arr[totalRows][totalRows], int sr, int sc) {
    bool isSuccessful = false;  // Flag to indicate if the game is successfully completed
    int i = 0;  // Counter for the number of iterations

    while (!isSuccessful) { // Main loop that executes until the game is finished

        start: ;  // Label to allow jumping back to the beginning of the loop

        char choice;

        if (i > 0) { // Ask the user whether to replace or add a value
            do {
                printf("Do you want to replace any value or want to add any value (press 'r' to replace or 'a' to add): ");
                scanf(" %c", &choice);

                if (choice != 'a' && choice != 'r') {
                    printf("Please choose the option from 'r' or 'a'.\n");
                }
            } while (choice != 'a' && choice != 'r');
        } else {
            choice = 'a';  // Default choice for the first iteration
        }

        switch (choice) {
            int rn, cn;  // Variables for row and column numbers

            case 'a':  // Add a value
            label_a: ;  // Label to allow jumping back to this point

                do { // Ask the user for the row and column numbers to add a value
                    printf("Enter the row number and column number where you want to add the value (in format row-column): ");
                    scanf("%d-%d", &rn, &cn);

                    if (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows) {
                        printf("Invalid row number or column number. Please try again.\n");
                    }
                } while (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows);

                if (!arr[rn - 1][cn - 1]) { // Check if the chosen cell is empty
                    char value;

                    // Ask the user for the value to add based on the game's dimensions
                    if (totalRows == 12) { // For a 12x12 game
                        do {
                            printf("Enter the value you want to add at row no %d, column no. %d from (1-12, A, B, C): ", rn, cn);
                            scanf(" %c", &value);
                            if (value < '1' || value > '9' && value != 'A' && value != 'B' && value != 'C') {
                                printf("Invalid value. Please choose from (1-12, A, B, C).\n");
                            } else {
                                break;
                            }
                        } while (1);
                    } else { // For 6x6 and 9x9
                        do {
                            printf("Enter the value you want to add at row no %d, column no %d from (1-%d): ", rn, cn, totalRows);
                            scanf(" %c", &value);

                            if (value < '1' || value > (totalRows + '0')) {
                                printf("Invalid value. Please choose from (1-%d)\n", totalRows);
                            }
                        } while (value < '1' || value > (totalRows + '0'));
                    }

                    // Convert character to integer
                    if (value >= '1' && value <= '9') {
                        value -= 48;
                    } else {
                        value -= 55;
                    }

                    // Check if the value is valid in the row, column, and subblock
                    if (checkRowsColumns(rn - 1, cn - 1, value, totalRows, arr) && checkSubblock(rn - 1, cn - 1, value, totalRows, sr, sc, arr)) {
                        arr[rn - 1][cn - 1] = value;
                        i++;  // Increment the iteration counter
                    } else {
                        printf("The value already exists in that row, column, or subblock. Please try again.\n");
                        goto start;  // Jump back to the beginning of the loop
                    }
                } else {
                    char pref;

                    if (i > 0) { // Ask the user whether to replace or choose another row and column
                        do {
                            printf("There is already a value at row no. %d, column %d. Press 'r' to replace or 'a' to choose another row and column: ", rn, cn);
                            scanf(" %c", &pref);

                            if (pref != 'a' && pref != 'r') {
                                printf("Please choose 'r' or 'a'.\n");
                            }
                        } while (pref != 'a' && pref != 'r');
                    } else {
                        printf("There is already a value. Please try again.\n");
                        goto label_a;  // Jump back to choosing another row and column
                    }

                    // Jump to the label according to user's choice
                    if (pref == 'r') {
                        goto label_r;
                    } else {
                        goto label_a;
                    }
                }
                break;

            case 'r':  // Replace a value
            label_r: ;  // Label to allow jumping back to this point

                bool isCoordinateSame = false;

                do { // Ask the user for the row and column numbers to replace a value
                    printf("Enter the row no. and column no. where you want to replace the value (in format row-column): ");
                    scanf("%d-%d", &rn, &cn);

                    if (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows) {
                        printf("Invalid row number or column number. Please try again.\n");
                    } else {
                        // Check if the chosen cell is computer-generated (a clue)
                        for (int i = 0; i < totalClues; i++) {
                            if (rn - 1 == all_rows[i] && cn - 1 == all_cols[i]) {
                                printf("You can't replace the value at row no. %d, column no. %d as it is a computer-generated clue. Please try again.\n", rn, cn);
                                isCoordinateSame = true;
                                goto start;  // Jump back to the beginning of the loop
                            }
                        }
                    }
                } while (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows || isCoordinateSame);

                if (arr[rn - 1][cn - 1]) { // Check if the chosen cell already has a value
                    char value;

                    // Ask the user for the new value based on the game's dimensions
                    if (totalRows == 12) { // For a 12x12 game
                        do {
                            printf("Enter the new value you want to replace at row no %d, column no. %d from (1-12, A, B, C): ", rn, cn);
                            scanf(" %c", &value);

                            if (value < '1' || value > '9' && value != 'A' && value != 'B' && value != 'C') {
                                printf("Invalid value. Please choose from (1-12, A, B, C).\n");
                            } else {
                                break;
                            }
                        } while (1);
                    } else { // For 6x6 and 9x9
                        do {
                            printf("Enter the new value you want to replace at row no %d, column no %d from (1-%d): ", rn, cn, totalRows);
                            scanf(" %c", &value);

                            if (value < '1' || value > totalRows + '0') {
                                printf("Invalid value. Please choose from (1-%d)\n", totalRows);
                            }
                        } while (value < '1' || value > totalRows + '0');
                    }

                    // Convert character to integer
                    if (value >= '1' && value <= '9') {
                        value -= 48;
                    } else {
                        value -= 55;
                    }

                    // Check if the new value is valid in the row, column, and subblock
                    if (checkRowsColumns(rn - 1, cn - 1, value, totalRows, arr) && checkSubblock(rn - 1, cn - 1, value, totalRows, sr, sc, arr)) {
                        arr[rn - 1][cn - 1] = value;
                    } else {
                        printf("The value already exists in that row, column, or subblock. Please try again.\n");
                        goto start;  // Jump back to the beginning of the loop
                    }
                } else {
                    char pref;

                    do { // Ask the user whether to add a value or choose another row and column to replace
                        printf("There is not any value at row no. %d, column no. %d. Press 'a' to add a value or 'r' to choose another row and column to replace: ", rn, cn);
                        scanf(" %c", &pref);

                        if (pref != 'a' && pref != 'r') {
                            printf("Please choose the option from 'r' or 'a'.\n");
                        }
                    } while (pref != 'a' && pref != 'r');

                    // Jump to the label according tothe user's choice
                    if (pref == 'r') {
                        goto label_r;
                    } else {
                        goto label_a;
                    }
                }
                break;
        }

        printMatrix(totalRows, sr, sc, arr); // Print the updated matrix

        // Check if all cells are filled (no zeros)
        bool noZero = true;
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalRows; j++) {
                if (arr[i][j] == 0) {
                    noZero = false;
                    break;
                }
            }
            if (!noZero) {
                break;
            }
        }

        // Check if the game is successfully completed based on the dimensions
        if (noZero) {
            switch (totalRows) {
                case 6:
                    if (checkingForEasy(arr, 6, 6)) {
                        printf("Congratulations. You win the game.\n");
                        isSuccessful = true;
                    }
                    break;
                case 9:
                    if (checkingForMedium(arr, 9, 9)) {
                        printf("Congratulations. You win the game.\n");
                        isSuccessful = true;
                    }
                    break;
                case 12 :
                    if(checkingForHard(arr, 12, 12)){
                        printf("Congratulations. You win the game.");
                        isSuccessful = true;
                    }
                    break;
            }
        }
    }
}

// Arguements include the initial array, the randomly chosen coordinates, the random number and dimension of the square matrix
// Checking columns and rows to see if any column or row collinear to the coordinates has a number equal to the inputted number
int checkRowsColumns(int randposr,int randposc,int num, int length, char ar[length][length]) {
    for (int k = 0; k < length; k++) { 
        if (num == ar[randposr][k] || num == ar[k][randposc]) {
          return 0; 
        }
    }
    return 1;
}

int checkSubblock(int randposr,int randposc,int num, int length, int sr, int sc, char ar[length][length]) {
    int srow = sr * (randposr / sr);  // sr and sc are the dimensions of the subblocks
    int scolumn = sc * (randposc / sc);
    for (int k = srow; k < srow + sr; k++) { // Now check the subblock that the address belongs to and find if any equal value exists
        for (int j = scolumn; j < scolumn + sc; j++) {
            if (num == ar[k][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the generated and updated both type of matrices for all dimensions
void printMatrix(int totalRows, int sr, int sc, char arr[totalRows][totalRows]){

    printf("\n");
    for (int i = 0; i < totalRows; i++) { // Iterate through rows
        if(!(i % sr)){ // Print horizontal separator for subgrid
            for(int j = 0; j < sr; j++){
                printf(" ");
                for(int k = 0; k < sc; k++){
                    printf(" -");
                }
                printf(" ");
            }
            printf("\n");
        }
        for (int j = 0; j < totalRows; j++) { // Iterate through columns
            if(!(j % sc)){ // Print vertical separator for subgrid
                printf("| ");
            }
            // Print the cell value or a space if the cell is empty
            printf("%c ", (arr[i][j]) ? (arr[i][j] >= 10 ? arr[i][j] + 55 : arr[i][j] + '0') : ' ');
            if(j + 1 == totalRows){ // Print the closing vertical separator for the last cell in the row
                printf("| ");
            }
        }
        printf("\n");
        if(i + 1 == totalRows){ // Print the horizontal separator for the last subgrid
            for(int j = 0; j < sr; j++){
                printf(" ");
                for(int k = 0; k < sc; k++){
                    printf(" -");
                }
                printf(" ");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int checkingForEasy(char arr[][6], int row, int col) {
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
	return flag;  
}

int checkingForMedium(char arr[][9], int row, int col) {
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
    return flag;
}

int checkingForHard(char arr[][12], int row, int col) {
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
