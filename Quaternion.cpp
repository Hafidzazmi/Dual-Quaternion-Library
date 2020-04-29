#include <math.h>
#include <array>
#include "Quaternion.h"
using namespace std;

// Create Quaternion
// INPUT  : Angle (Degrees) , Direction of rotation <array 3>
// OUTPUT :  Quaternion <array 4>
array<double, 4> Quaternion::Create(double theta, array<int, 3> direction) {
  array<double, 4> Output ;

  //Convert degree to radians
  theta = theta*3.14159/180;

  Output[0] = cos(theta/2);
  Output[1] = direction[0]*sin(theta/2);;
  Output[2] = direction[1]*sin(theta/2);
  Output[3] = direction[2]*sin(theta/2);
  return Output;
}

// Conjugate Quaternion P
// INPUT  : Quaternion <array 4>
// OUTPUT :  Quaternion <array 4>
array<double, 4> Quaternion::Conjugate(array<double,4> p){
  array<double, 4> Output ;

     Output[0] = p[0];
     Output[1] = -1*p[1];
     Output[2] = -1*p[2];
     Output[3] = -1*p[3];

   return Output;
}

// Normalize Quaternion P
// INPUT  : Quaternion <array 4>
// OUTPUT :  ||P||
double Quaternion::Normalize(array<double,4> p){
  double Output ;

     Output = p[0]*p[0] + p[1]*p[1] + p[2]*p[2] + p[3]*p[3];

   return sqrt(Output);
}

// Add Quaternion P + Q
// INPUT  : Quaternion <array 4> , Quaternion <array 4>
// OUTPUT :  Quaternion <array 4>
array<double, 4> Quaternion::Add(array<double,4> p, array<double,4> q){
  array<double, 4> Output ;

     Output[0] = p[0] + q[0];
     Output[1] = p[1] + q[1];
     Output[2] = p[2] + q[2];
     Output[3] = p[3] + q[3];

   return Output;
}

// Subtract Quaternion P - Q
// INPUT  : Quaternion <array 4> , Quaternion <array 4>
// OUTPUT :  Quaternion <array 4>
array<double, 4> Quaternion::Subtract(array<double,4> p, array<double,4> q){
  array<double, 4> Output ;

     Output[0] = p[0] - q[0];
     Output[1] = p[1] - q[1];
     Output[2] = p[2] - q[2];
     Output[3] = p[3] - q[3];

   return Output;
}

// Multiply Quaternion P * Q (matrix form)
// INPUT  : Quaternion <array 4> , Quaternion <array 4>
// OUTPUT :  Quaternion <array 4>
array<double, 4> Quaternion::Multiply(array<double,4> p, array<double,4> q){
  array<double, 4> Output ;

     Output[0] = p[0]*q[0] - p[1]*q[1] - p[2]*q[2] - p[3]*q[3];
     Output[1] = p[0]*q[1] + p[1]*q[0] + p[2]*q[3] - p[3]*q[2];
     Output[2] = p[0]*q[2] - p[1]*q[3] + p[2]*q[0] + p[3]*q[1];
     Output[3] = p[0]*q[3] + p[1]*q[2] - p[2]*q[1] + p[3]*q[0];

   return Output;
}

// Multiply Quaternion P * X (X is a single value)
// INPUT  : Quaternion <array 4> , Scalar X
// OUTPUT :  Quaternion <array 4>
array<double, 4> Quaternion::MultiplyScalar(array<double,4> p, double x){
  array<double, 4> Output ;

     Output[0] = p[0]*x;
     Output[1] = p[1]*x;
     Output[2] = p[2]*x;
     Output[3] = p[3]*x;

   return Output;
}
