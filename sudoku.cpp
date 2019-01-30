#include<bits/stdc++.h>
using namespace std;

bool CheckRow(char arr[][9], int row){
	unordered_set<char> set;
	 for (int i = 0; i < 9; i++) {  
        if (set.find(arr[row][i]) != set.end()) 
            return false; 
  
        if (arr[row][i] != '.') 
            set.insert(arr[row][i]); 
    } 
    return true; 
}

bool CheckCol(char arr[][9], int col) 
{ 
	unordered_set<char> set;
    for (int i = 0; i < 9; i++) { 
        if (set.find(arr[i][col]) != set.end()) 
            return false; 

        if (arr[i][col] != '.') 
            set.insert(arr[i][col]); 
    } 
    return true; 
} 

bool CheckSquare(char arr[][9], int startRow, int startCol) 
{ 
    unordered_set<char> set; 
    for (int row = 0; row < 3; row++) { 
        for (int col = 0; col < 3; col++) { 
            char curr = arr[row + startRow][col + startCol]; 
  		    if (set.find(curr) != set.end()) 
                return false; 
  
            if (curr != '.') 
                set.insert(curr); 
        } 
    } 
    return true; 
}

bool isValid(char arr[][9], int row, int col) 
{ 
    return CheckRow(arr, row) && CheckCol(arr, col) && CheckSquare(arr, row - row % 3, col - col % 3); 
} 

bool Result(char arr[][9], int n) 
{ 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (!isValid(arr, i, j)) 
                return false; 
    return true; 
} 


int main() 
{ 
    char board[9][9] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
                         { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
                         { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
                         { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
                         { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
                         { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
                         { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
                         { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
                         { '.', '.', '.', '.', '8', '.', '.', '7', '9' } }; 
  
    cout << (Result(board, 9) ? "Valid!\n" : "Not valid!\n"); 
    return 0; 
} 
