
#ifndef QUATERNION_H
#define QUATERNION_H

// #include <vector>
#include <array>
using namespace std;

namespace Quaternion{

// Create Quaternion
array<double, 4> Create(double, array<int, 3>);

// Conjugate Quaternion P ^ -1
array<double, 4> Conjugate(array<double, 4>);

// Normalize Quaternion ||P||
double Normalize(array<double, 4>);

// Add Quaternion P + Q
array<double, 4> Add(array<double, 4>, array<double, 4>);

// Subtract Quaternion P - Q
array<double, 4> Subtract(array<double, 4>, array<double, 4>);

// Multiply Quaternion P * Q [matrix form]
array<double, 4> Multiply(array<double, 4>, array<double, 4>);

// Multiply Scalar Quaternion P * X [X Scalar value]
array<double, 4> MultiplyScalar(array<double, 4>, double);

}
#endif
