# Dual-Quaternion-Library-C++

This library was build for Quaternion & Dual Quaternion Calculation Tutorial. <br><br>

### Quaternion::

| Name | Type | Description |
| --- | --- | --- |
| [**Create**](#quaternioncreate) | std::array<double, 4> | Create Quaternion Rotation, Angle in Degree |
| [**Conjugate**](#quaternionconjugate) | std::array<double, 4> | Quaternion Conjugate |
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
Create a quaternion rotation based on the equation below :

<img src="http://www.sciweavers.org/tex2img.php?eq=q%3D%20%5Bcos%28%20%5Ctheta%20%2F2%29%2C%20d%2Asin%28%20%5Ctheta%20%2F2%29%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="q= [cos( \theta /2), d*sin( \theta /2)]" width="233" height="19" />


**Example :**<br>
double Angle = 90; *//in Degrees*<br>
std::array<int, 3> DirectionOfRotation = {0,1,0};<br>
std::array<double, 4> Quaternion1; <br>
Quaternion1 = Quaternion::Create(Angle,DirectionOfRotation);


### Quaternion::Conjugate
Return Quaternion Conjugate based on the equation below :<br>
<img src="http://www.sciweavers.org/tex2img.php?eq=q = [cos( \theta /2), -d*sin( \theta /2)]&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="q = [cos( \theta /2), -d*sin( \theta /2)]" width="247" height="19" />

**Example :**<br>
Quaternion::Conjugate([Quaternion1](#quaternioncreate));


### Note : 
This library used std::array<> <br>
Any improvment are appreciated
