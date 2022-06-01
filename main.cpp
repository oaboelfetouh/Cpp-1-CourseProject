//
//  main.cpp
//  cpp course project
//
//  Created by Omar Mohamed Aboelfetouh on 5/16/22.
//  Copyright © 2022 well... that's hard. All rights reserved.
//
#include <iostream>
#include <cmath>

using namespace std;
bool condition = true;

int arr1[10][10];
int arr2[10][10];
float result[10][10] ;
float inversearray[10][10];

// functions for the operations
void Addition (int A[10][10],int B[10][10]){
   for(int i = 0; i < 10 ; i ++){
        for(int j = 0 ; j < 10; j ++ ){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}
void Subtraction (int A[10][10],int B[10][10]){
   for(int i = 0; i < 10 ; i ++){
        for(int j = 0 ; j < 10; j ++ ){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}
void Multiplication (int A[10][10],int B[10][10], int x1, int y2, int k){
        // code here!
        for (int x = 0; x < x1 ; x++){
                for (int y = 0; y < y2; y ++){
                    result[x][y] = 0;
                    for (int i = 0; i < k; i++){
                        result[x][y] += A[x][i] * B[i][y];
                    }
                }
            }
}


void Multiplication_fordivision (int A[10][10],float B[10][10], int x1, int y2, int k){
        // code here!
        for (int x = 0; x < x1 ; x++){
                for (int y = 0; y < y2; y ++){
                    result[x][y] = 0;
                    for (int i = 0; i < k; i++){
                        result[x][y] += A[x][i] * B[i][y];
                    }
                }
            }
}
double det( int m ,int arr[10][10]){
    double ans  = 0;
    if(m==1 || m==2){
        if(m == 1){
            return arr[0][0];
        }
        else if (m == 2){
            return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
        }
    }
    else{
        int sign = 1;
        for (int i = 0; i < m; i ++){
            int factor = arr[0][i];
            int smaller_array[10][10];
            for (int x = 0; x < 10;x ++ ){
                for (int y = 0; y < 10 ; y++){
                    if (y < i)
                        smaller_array[x][y] = arr[x+1][y];
                    else if (i <= y)
                        smaller_array[x][y] = arr[x+1][y+1];
                }
            }
            /*
            for (int x = 0; x < m-1; x++){
                   for (int y = 0; y < m-1; y++){
                       cout << smaller_array[x][y] << " " ;
                   }
                   cout << endl;
               }
           */
            
            ans += sign * factor * det(m-1 ,smaller_array);
            
            sign = pow(-1, i+1);
        }
        
    }
    return ans;
}

void inverse(int arr[10][10]){
    long det_value;
   
    for (int x = 0; x < 3; x++){
          for (int y = 0; y < 3; y++){
            if (x == 0 && y == 0){
                  int smallerarray[10][10] = {{arr[1][1],arr[1][2]},{arr[2][1],arr[2][2]}};
                  det_value = det(2, smallerarray);
                inversearray[y][x] =  float(det_value)/ (det(3, arr));
              }
            else if (x == 0 && y == 1){
              int smallerarray[10][10] = {{arr[1][0],arr[1][2]},{arr[2][0],arr[2][2]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] = -1 * float(det_value)/ (det(3, arr));
            }
            else if (x == 0 && y == 2){
              int smallerarray[10][10] = {{arr[1][0],arr[1][1]},{arr[2][0],arr[2][1]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] =  float(det_value)/ (det(3, arr));
              }
            else if (x == 1 && y == 0){
              int smallerarray[10][10] = {{arr[0][1],arr[0][2]},{arr[2][1],arr[2][2]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] = -1 * float(det_value)/ (det(3, arr));
              }
            else if (x == 1 && y == 1){
              int smallerarray[10][10] = {{arr[0][0],arr[0][2]},{arr[2][0],arr[2][2]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] =  float(det_value)/ (det(3, arr));
              }
            else if (x == 1 && y == 2){
              int smallerarray[10][10] = {{arr[0][0],arr[0][1]},{arr[2][0],arr[2][1]}};
                  det_value = det(2, smallerarray);
                 inversearray[y][x] = -1 * float(det_value)/ (det(3, arr));
              }
            else if (x == 2 && y == 0){
              int smallerarray[10][10] = {{arr[0][1],arr[0][2]},{arr[1][1],arr[1][2]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] =  float(det_value)/ (det(3, arr));
              }
            else if (x == 2 && y == 1){
              int smallerarray[10][10] = {{arr[0][0],arr[0][2]},{arr[1][0],arr[1][2]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] = -1 * float(det_value)/ (det(3, arr));
              }
            else if (x == 2 && y == 2){
              int smallerarray[10][10] = {{arr[0][0],arr[0][1]},{arr[1][0],arr[1][1]}};
                  det_value = det(2, smallerarray);
                  inversearray[y][x] =  float(det_value)/ (det(3, arr));
              }
             
          }
      }
}

// main :))
int main() {
    // the inputs
    cout << "Please enter dimensions of Matrix A:" << endl;
    int x1,y1; cin >> x1 >> y1 ;
    cout << "Please enter dimensions of Matrix B:" << endl;
    int x2,y2; cin >> x2 >> y2;
    cout << "Please enter values of Matrix A:" << endl;
    for(int i = 0; i < x1 ; i ++){
        for(int j = 0 ; j < y1; j ++ ){
            cin >> arr1[i][j];
        }
    }
    cout << "Please enter values of Matrix B:" << endl;
    for(int i = 0; i < x2 ; i ++){
        for(int j = 0 ; j < y2; j ++ ){
            cin >> arr2[i][j];
        }
    }
    // the opertation
    while(true){
            cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
            int operation; cin >> operation;
            if (operation == 7){
                cout << "Thank you!"<< endl;
                  break;
            }
            switch(operation){
                    case 1:
                        if (x1 == x2 && y1 == y2){
                              Addition(arr1, arr2);
                            for(int i = 0; i < x1 ; i ++){
                                for(int j = 0 ; j < y1; j ++ ){
                                    cout << result[i][j] << " ";
                                }
                                 cout <<'\n' ;
                            }
                        }
                        else
                            cout << "The operation you chose is invalid for the given matrices." << endl;
                      break;
                    case 2:
                    if (x1 == x2 && y1 == y2){
                          Subtraction(arr1, arr2);
                        for(int i = 0; i < x1 ; i ++){
                            for(int j = 0 ; j < y1; j ++ ){
                                cout << result[i][j] << " ";
                            }
                             cout <<'\n' ;
                        }
                    }
                    else
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                      break;
                        case 3:
                    if (y1 == x2){
                        // parameters are arr1 arr2 the outer dim and one of the inner ones
                        // dim1(3,6) dim2(6,2) -> 3,2,6
                        Multiplication(arr1, arr2, x1,y2,x2);
                        for(int i = 0; i < x1 ; i ++){
                            for(int j = 0 ; j < y2; j ++ ){
                                cout << result[i][j] << " ";
                            }
                            cout <<'\n' ;
                        }
                    }
                    else
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                      break;
                    case 4:
                    if (x1 ==3 && x2 == 3 && y1 == 3 && y2 == 3 && det(3, arr2) != 0 ){
                        inverse(arr2);
                        Multiplication_fordivision(arr1, inversearray, 3, 3, 3);
                        for(int i = 0; i < 3 ; i ++){
                            for(int j = 0 ; j < 3; j ++ ){
                                if (round(result[i][j]) == -0)
                                cout << 0  << " ";
                                else
                                    cout << round(result[i][j]) << " ";
                            }
                            cout <<'\n' ;
                        }
                        
                    }
                    else
                         cout << "The operation you chose is invalid for the given matrices." << endl;
                      break;
                    case 5:
                    if (x1 == y1){
                        // code here
                        cout << det(x1, arr1) << endl;
                    }
                    else
                         cout << "The operation you chose is invalid for the given matrices." << endl;
                      break;
                    case 6:
                    if (x2 == y2){
                        // code here
                         cout << det(x2, arr2) << endl;
                    }
                    else
                         cout << "The operation you chose is invalid for the given matrices." << endl;
                      break;
            }
    }
    return 0;
}
