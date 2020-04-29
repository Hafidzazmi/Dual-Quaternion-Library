#include <math.h>
#include <array>
#include "Quaternion.h"
#include "DualQuaternion.h"
using namespace std;

// Create Dual Quaternion
// INPUT  : Angle (Degrees) , Direction of rotation <array 3>, Translation <array 4>
// OUTPUT :  Dual Quaternion <array 8>
array<double, 8> DualQuaternion::Create(double theta, array<int, 3> direction, array<double, 4> translation) {
  array<double, 4> QuaternionScalar, QuaternionVector;
  array<double, 8> Output ;

  QuaternionScalar = Quaternion::Create(theta, direction);
  QuaternionVector = Quaternion::MultiplyScalar(Quaternion::Multiply(translation,QuaternionScalar), 0.5);

  for(int i=0; i <4; i++){
    Output[i]     = QuaternionScalar[i];
    Output[i + 4] = QuaternionVector[i];
  }

  return Output;
}

// Grab Dual Quaternion Pure Rotation
// INPUT  : Dual Quaternion <array 8>
// OUTPUT :  Dual Quaternion <array 8>
array<double, 8> DualQuaternion::Rotation(array<double, 8> p) {
  array<double, 8> Output ;

  for(int i=0; i <4; i++){
    Output[i]     = p[i];
    Output[i + 4] = 0;
  }

  return Output;
}

// Grab Quaternion Translation
// INPUT  : Dual Quaternion <array 8>
// OUTPUT :  Vector Quaternion <array 4>
array<double, 4> DualQuaternion::Translation(array<double, 8> p) {
  array<double, 4> QuaternionScalar, QuaternionVector;
  array<double, 4> Output ;

  for(int i=0; i <4; i++){
    QuaternionScalar[i] = p[i];
    QuaternionVector[i] = p[i + 4];
  }

  Output = Quaternion::MultiplyScalar(Quaternion::Multiply(QuaternionVector, Quaternion::Conjugate(QuaternionScalar)), 2);

  return Output;
}


// Conjugate Quaternion P
// INPUT  : Quaternion <array 4>
// OUTPUT :  Quaternion <array 4>
array<double, 8> DualQuaternion::Conjugate(array<double,8> p){
  array<double, 4> QuaternionScalar, QuaternionVector;
  array<double, 8> Output ;

  for(int i=0; i <4; i++){
    QuaternionScalar[i] = p[i];
    QuaternionVector[i] = p[i + 4];
  }
  QuaternionScalar = Quaternion::Conjugate(QuaternionScalar);
  QuaternionVector = Quaternion::Conjugate(QuaternionVector);

  for(int i=0; i <4; i++){
    Output[i]     = QuaternionScalar[i];
    Output[i + 4] = QuaternionVector[i];
  }

   return Output;
}

// Add Dual Quaternion P + Q
// INPUT  : Dual Quaternion <array 8> , Dual Quaternion <array 8>
// OUTPUT :  Dual Quaternion <array 8>
array<double, 8> DualQuaternion::Add(array<double,8> p, array<double,8> q){
  array<double, 8> Output ;
  for(int i=0; i <8; i++){
    Output[i] = p[i] + q[i];
  }
  return Output;
}


// Subtract Dual Quaternion P - Q
// INPUT  : Dual Quaternion <array 8> , Dual Quaternion <array 8>
// OUTPUT :  Dual Quaternion <array 8>
array<double, 8> DualQuaternion::Subtract(array<double,8> p, array<double,8> q){
  array<double, 8> Output ;
  for(int i=0; i <8; i++){
    Output[i] = p[i] - q[i];
  }
  return Output;
}

// Multiply Dual Quaternion P * Q (matrix form)
// INPUT  : Dual Quaternion <array 8> , Dual Quaternion <array 8>
// OUTPUT : Dual Quaternion <array 8>
array<double, 8> DualQuaternion::Multiply(array<double,8> p, array<double,8> q){
  array<double, 4> QuaternionScalar, QuaternionVector;
  array<double, 4> QuaternionScalarP, QuaternionVectorP;
  array<double, 4> QuaternionScalarQ, QuaternionVectorQ;
  array<double, 8> Output ;

  for(int i=0; i <4; i++){
    QuaternionScalarP[i] = p[i];
    QuaternionVectorP[i] = p[i + 4];
    QuaternionScalarQ[i] = q[i];
    QuaternionVectorQ[i] = q[i + 4];
  }

  QuaternionScalar = Quaternion::Multiply(QuaternionScalarP,QuaternionScalarQ);
  QuaternionVector = Quaternion::Add( Quaternion::Multiply(QuaternionScalarP,QuaternionVectorQ), Quaternion::Multiply(QuaternionVectorP,QuaternionScalarQ) );

  for(int i=0; i <4; i++){
    Output[i]     = QuaternionScalar[i];
    Output[i + 4] = QuaternionVector[i];
  }

  return Output;
}
