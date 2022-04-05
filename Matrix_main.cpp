// #include "Matrix.hpp"
// #include <limits.h>


// // How to run: g++ -o a.out Matrix.cpp Matrix_main.cpp Matrix.hpp
// using namespace std;

// std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};

// std::string creat_mat_format(std::string data){
//     for (int i = 0; i < data.size(); i++){
//         if(data.at(i) == '|'){
//             data[i] = ' ';
//         }
//     }
//     return data;
// }
// namespace zich{
//     void action(int act, Matrix &mat, Matrix &mat2){
//         switch (act){
//         case 0:
//             exit(0);
//         case 1:

//             break;
//         case 2:

//             break;
//         case 3:

//             break;
//         case 4:

//             break;
//         case 5:

//             break;
//         case 6:

//             break;
//         case 7:

//             break;
//         case 8:

//             break;
//         case 9:

//             break;
//         case 10:

//             break;
//         case 11:

//             break;
//         case 12:

//             break;
//         case 13:

//             break;
//         case 14:

//             break;            
//         default:
//             break;
//         }
//     }
// }


// int main(){
//     std::string data;
//     std::string data2;

//     cout << "Chose row & col size\n";
//     int row = 0;
//     int col = 0;
//     cin >> row >> col;

//     zich::Matrix a{row, col};

//     cout << "Enter matrix data in this format\n"
//         <<"example 2x2 ==> [val1|val2],|[val3|val4]\n";
//     cin >> data;
//     data = creat_mat_format(data);
//     std::stringstream is1;
//     is1 << data;
//     is1 >> a;

//     zich::Matrix b{row, col};
//     cout << "Enter the next matrix data\n";
//     cin >> data2;
//     data2 = creat_mat_format(data2);
//     std::stringstream is2;
//     is2 << data2;
//     is2 >> b;

//     cout << "Enter an action num:\n"
//         << "exit: 0,\n ==: 1, <=: 2, >=: 3, >: 4, <: 5\n"
//         << "mat*mat: 6, scalar*mat: 7, mat*=mat: 8, mat*=scalar\n"
//         << "mat-mat: 9, mat-=mat: 10, -mat=: 11\n"
//         << "mat++: 12, ++mat: 13, mat--: 14, --mat: 15\n";
    
//     while (1){    
//         int act;
//         cin >> act;
//         zich::action(act,a ,b);
//     }
//     return 0;
// }
