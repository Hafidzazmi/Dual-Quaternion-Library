# Dual-Quaternion-Library-C++

This library was build for Quaternion & Dual Quaternion Calculation Tutorial. <br><br>

### Quaternion::

| Name | Type | Description |
| --- | --- | --- |
| [**Create**](#quaternioncreate) | std::array<double, 4> | Create Quaternion Rotation, Angle in Degree |
| [**Conjugate**](#quaternionconjugate) | std::array<double, 4> | Quaternion Conjugate |
| [**Normalize**](#quaternionnormalize) | double | Normalize Quaternion , Unit Quaternion = 1 |
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

<img src="http://www.sciweavers.org/tex2img.php?eq=q%3D%20%5Bcos%28%20%5Ctheta%20%2F2%29%2C%20d%2Asin%28%20%5Ctheta%20%2F2%29%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="q= [cos( \theta /2), d*sin( \theta /2)]" width="233" height="19" /><br>
where : <br>
<img src="http://www.sciweavers.org/tex2img.php?eq=%20q_%7Bs%7D%20%3D%20cos%28%20%5Ctheta%20%2F2%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt=" q_{s} = cos( \theta /2)" width="117" height="19" /><br>
<img src="http://www.sciweavers.org/tex2img.php?eq= q_{v} = d*sin( \theta /2)&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt=" q_{v} = d*sin( \theta /2)" width="146" height="19" /><br>


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



### Quaternion::Normalize
Return Quaternion Normalize based on the equation below :<br>
<img src="https://bit.ly/3aT4S2d" align="center" border="0" alt="||q|| = \sqrt{q0^{2} + q1^{2} + q2^{2} + q3^{2}} " width="256" height="26" /><br>
***Note : Normalize Unit Quaternion will return 1***

**Example :**<br>
Quaternion::Normalize([Quaternion1](#quaternioncreate));


### Quaternion::Add
Add two Quaternions (P + Q) based on the equation below :<br>
<img src="http://www.sciweavers.org/tex2img.php?eq=%20p%20%2B%20q%20%3D%20%5Bp_%7Bs%7D%20%2B%20q_%7Bs%7D%2Cp_%7Bv%7D%20%2B%20q_%7Bv%7D%5D%20&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt=" p + q = [p_{s} + q_{s},p_{v} + q_{v}] " width="208" height="19" /><br>

**Example :**<br>
Quaternion::Add([Quaternion1](#quaternioncreate),Quaternion2);



### Note : 
This library used std::array<> <br>
Any improvment are appreciated
