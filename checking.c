
#include <stdio.h>
#include <stdbool.h>

int checkingforeasy(char arr[][6], int row, int col) {
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

 int checkingformedium(char arr[][9], int row, int col) {
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

 int checkingforhard(char arr[][12], int row, int col) {
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

