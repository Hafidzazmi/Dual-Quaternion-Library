# Dual-Quaternion-Library-C++

This library was build for Dual Quaternion Calculation Applications. <br><br>

### Quaternion::

| Name | Type | Description |
| --- | --- | --- |
| **Create** | array<double, 4> | Create Quaternion Rotation, Angle in Degree |
| **Conjugate** | array<double, 4> | Quaternion Conjugate |
| **Normalize** | double | Normalize Quaternion , Unit Quaternion = 1 |
| **Add** | array<double, 4> | Add Two Quaternions |
| **Subtract** | array<double, 4> | Subtract Two Quaternions |
| **Multiply** | array<double, 4> | Multiply Two Quaternions |
| **MultiplyScalar** | array<double, 4> | Multiply Quaternion with scalar value |



### DualQuaternion::

| Name | Type | Description |
| --- | --- | --- |
| **Create** | array<double, 8> | Create Dual Quaternion Rotation and Translation, Angle in Degree |
| **Rotation** | array<double, 8> | Return Dual Quaternion Pure Rotation |
| **Translation** | array<double, 4> | Return Vector Quaternion Translation |
| **Conjugate** | array<double, 8> | Dual Quaternion Conjugate |
| **Add** | array<double, 8> | Add Two Dual Quaternions |
| **Subtract** | array<double, 8> | Subtract Two Dual Quaternions |
| **Multiply** | array<double, 8> | Multiply Two Dual Quaternions |

### Note : 
This library used std::array<> <br>
Any improvment are appreciated
