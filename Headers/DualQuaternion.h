
#ifndef DUALQUATERNION_H
#define DUALQUATERNION_H

// #include <vector>
#include <array>
#include "Quaternion.h"
using namespace std;

namespace DualQuaternion{

  // Create Dual Quaternion
  array<double, 8> Create(double, array<int, 3>, array<double, 4>);

  // Grab Dual Quaternion Pure Rotation
  array<double, 8> Rotation(array<double, 8>);

  // Grab Vecotr Quaternion Translation
  array<double, 4> Translation(array<double, 8>);

  // Conjugate Dual Quaternion P ^ -1
  array<double, 8> Conjugate(array<double, 8>);

  // Add Dual Quaternion P + Q
  array<double, 8> Add(array<double, 8>, array<double, 8>);

  // Subtract Dual Quaternion P + Q
  array<double, 8> Subtract(array<double, 8>, array<double, 8>);

  // Multiply Dual Quaternion P * Q
  array<double, 8> Multiply(array<double, 8>, array<double, 8>);
}
#endif
