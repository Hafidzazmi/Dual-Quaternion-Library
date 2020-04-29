# Dual-Quaternion-Library-C++

This library was build for Dual Quaternion Calculation Applications. <br><br>

### Quaternion::

| Name | Type | Description |
| --- | --- | --- |
| [**Create**](#quaternion::create) | std::array<double, 4> | Create Quaternion Rotation, Angle in Degree |
| **Conjugate** | std::array<double, 4> | Quaternion Conjugate |
| **Normalize** | double | Normalize Quaternion , Unit Quaternion = 1 |
| **Add** | std::array<double, 4> | Add Two Quaternions |
| **Subtract** | std::array<double, 4> | Subtract Two Quaternions |
| **Multiply** | std::array<double, 4> | Multiply Two Quaternions |
| **MultiplyScalar** | std::array<double, 4> | Multiply Quaternion with scalar value |



### DualQuaternion::

| Name | Type | Description |
| --- | --- | --- |
| **Create** | std::array<double, 8> | Create Dual Quaternion Rotation and Translation, Angle in Degree |
| **Rotation** | std::array<double, 8> | Return Dual Quaternion Pure Rotation |
| **Translation** | std::array<double, 4> | Return Vector Quaternion Translation |
| **Conjugate** | std::array<double, 8> | Dual Quaternion Conjugate |
| **Add** | std::array<double, 8> | Add Two Dual Quaternions |
| **Subtract** | std::array<double, 8> | Subtract Two Dual Quaternions |
| **Multiply** | std::array<double, 8> | Multiply Two Dual Quaternions |


### Quaternion::Create

### Note : 
This library used std::array<> <br>
Any improvment are appreciated
