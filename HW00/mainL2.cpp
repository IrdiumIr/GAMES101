#include<cmath>
#include"C:\VSCodeCpp\eigen-3.4.0\Eigen\Core"
#include"C:\VSCodeCpp\eigen-3.4.0\Eigen\Dense"
#include<iostream>

int main(){

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
    // vector add
    std::cout << "Example of product \n";
    std::cout << v.dot(w) << std::endl;
    std::cout << v.cross(w) << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i + j << std::endl;
    std::cout << i * 2.0f << std::endl;
    std::cout << i * j << std::endl;
    std::cout << i * v << std::endl;

    // TO USE Homogeneous to calculate P'
    Eigen::Vector3f P(2,1,1);//homo
    Eigen::Matrix3f M;

    float theta = 45.0f * (3.1415926f / 180.0f);

    M << cos(theta), -sin(theta), 1, sin(theta), cos(theta), 2, 0, 0, 1;

    Eigen::Vector3f Pt = M * P;
    std::cout << Pt << std::endl;

    return 0;
}