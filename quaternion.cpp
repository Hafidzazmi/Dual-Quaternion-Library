#include<iostream>
#include <math.h>
using namespace std;

struct arrayThree {

  // array three class

  double arrayCreateThree[3];

}

struct arrayFour {

  // array class builder
  double arrayCreate[4];

};

struct arrayEight {

  // array class builder
  double arrayCreateEight[8];

};

struct arrayThree crossProduct ( double matrixA, double matrixB){

  

}


struct arrayFour quaternion(double theta, int direction[3]){

  //create quaternion

  struct arrayFour quaternionOne;

  quaternionOne.arrayCreate[0] = cos(theta/2);
  quaternionOne.arrayCreate[1] = direction[0]*sin(theta/2);
  quaternionOne.arrayCreate[2] = direction[1]*sin(theta/2);
  quaternionOne.arrayCreate[3] = direction[2]*sin(theta/2);

  return quaternionOne;
}

struct arrayFour quaternionConjugate(double quaternion[4]){

  //quaternion conjugate

  struct arrayFour quaternionConjugateResult;

  quaternionConjugateResult.arrayCreate[0] = quaternion[0];
  quaternionConjugateResult.arrayCreate[1] = -quaternion[1];
  quaternionConjugateResult.arrayCreate[2] = -quaternion[2];
  quaternionConjugateResult.arrayCreate[3] = -quaternion[3];

  return quaternionConjugateResult;

}

struct arrayFour quaternionMultiplication(double quaternionQ[4], double quaternionP[4]){
  struct arrayFour quaternionProductQP;

    // didnt use the operation
    // quaternion multiplication matrix form
    // q0p0 - q1p1 - q2p2 - q3p3
    // q0p1 + q1p0 + q2p3 - q3p2
    // q0p2 - q1p3 + q2p0 + q3p1
    // q0p3 + q1p2 - q2p1 + q3p0

   quaternionProductQP.arrayCreate[0] = quaternionQ[0]*quaternionP[0] - quaternionQ[1]*quaternionP[1] - quaternionQ[2]*quaternionP[2] - quaternionQ[3]*quaternionP[3];

   quaternionProductQP.arrayCreate[1] = quaternionQ[0]*quaternionP[1] + quaternionQ[1]*quaternionP[0] + quaternionQ[2]*quaternionP[3] - quaternionQ[3]*quaternionP[2];

   quaternionProductQP.arrayCreate[2] = quaternionQ[0]*quaternionP[2] - quaternionQ[1]*quaternionP[3] + quaternionQ[2]*quaternionP[0] + quaternionQ[3]*quaternionP[1];

   quaternionProductQP.arrayCreate[3] = quaternionQ[0]*quaternionP[3] + quaternionQ[1]*quaternionP[2] - quaternionQ[2]*quaternionP[1] + quaternionQ[3]*quaternionP[0];

   return quaternionProductQP;

}

struct arrayFour quaternionSubstraction(double quaternionQ[4], double quaternionP[4]){

  //substraction of quaternion with quaternion

  struct arrayFour quaternionSubstractionQP;

  quaternionSubstractionQP.arrayCreate[0] = quaternionQ[0] - quaternionP[0];
  quaternionSubstractionQP.arrayCreate[1] = quaternionQ[1] - quaternionP[1];
  quaternionSubstractionQP.arrayCreate[2] = quaternionQ[2] - quaternionP[2];
  quaternionSubstractionQP.arrayCreate[3] = quaternionQ[3] - quaternionP[3];

  return quaternionSubstractionQP;
}

struct arrayFour quaternionAddition(double quaternionQ[4], double quaternionP[4]){

  //substraction of quaternion with quaternion

  struct arrayFour quaternionAdditionQP;

  quaternionAdditionQP.arrayCreate[0] = quaternionQ[0] + quaternionP[0];
  quaternionAdditionQP.arrayCreate[1] = quaternionQ[1] + quaternionP[1];
  quaternionAdditionQP.arrayCreate[2] = quaternionQ[2] + quaternionP[2];
  quaternionAdditionQP.arrayCreate[3] = quaternionQ[3] + quaternionP[3];

  return quaternionAdditionQP;
}


struct arrayFour quaternionSingleMultiplication(double quaternion[4], double valueM){

  //multiplication of single value in a matrix quaternion

  struct arrayFour quaternionAnswer;

  quaternionAnswer.arrayCreate[0] = valueM * quaternion[0];
  quaternionAnswer.arrayCreate[1] = valueM * quaternion[1];
  quaternionAnswer.arrayCreate[2] = valueM * quaternion[2];
  quaternionAnswer.arrayCreate[3] = valueM * quaternion[3];

  return quaternionAnswer;
}


struct arrayFour quaternionDualPart(double quaternion[4], double point[4]){

  //Dual quaternion part based on screw theory

  struct arrayFour quaternionDualPartQ;

  //Q * p
  struct arrayFour quaternionQP = quaternionMultiplication(quaternion,point);

  //Q_conjugate
  struct arrayFour quaternionQConjugate = quaternionConjugate(quaternion);

  //Q * p * Q_conjugate
  struct arrayFour quaternionQPQConjugate = quaternionMultiplication(quaternionQP.arrayCreate,quaternionQConjugate.arrayCreate);

  //p - (Q * p * Q_conjugate)
  struct arrayFour quaternionPMinusQPQConjugate = quaternionSubstraction(point,quaternionQPQConjugate.arrayCreate);

  //[ p - (Q * p * Q_conjugate) ] * Q
  struct arrayFour quaternionPMinusQPQConjugateQ = quaternionMultiplication(quaternionPMinusQPQConjugate.arrayCreate,quaternion);

  // 0.5 * (p - QpQ_conjugate)Q
  struct arrayFour answerQuaternion = quaternionSingleMultiplication(quaternionPMinusQPQConjugateQ.arrayCreate,0.5);

  return answerQuaternion;

}


struct arrayEight createDualQuaternion(double quaternion[4], double quaternionDualPart[4]){

  // Create dual quaternion

  struct arrayEight dualQuaternion ;
  dualQuaternion.arrayCreateEight[0] = quaternion[0];
  dualQuaternion.arrayCreateEight[1] = quaternion[1];
  dualQuaternion.arrayCreateEight[2] = quaternion[2];
  dualQuaternion.arrayCreateEight[3] = quaternion[3];
  dualQuaternion.arrayCreateEight[4] = quaternionDualPart[0];
  dualQuaternion.arrayCreateEight[5] = quaternionDualPart[1];
  dualQuaternion.arrayCreateEight[6] = quaternionDualPart[2];
  dualQuaternion.arrayCreateEight[7] = quaternionDualPart[3];

  return dualQuaternion;

}

struct arrayEight dualQuaternionConjugate(double dualQuaternion[8]){

  // conjugate dual quaternion

  struct arrayEight dualQuaternionConjugateAnswer;
  dualQuaternionConjugateAnswer.arrayCreateEight[0] = dualQuaternion[0];

  for (int i =1; i<8; i++){
    dualQuaternionConjugateAnswer.arrayCreateEight[i] = -dualQuaternion[i];
  }

  return dualQuaternionConjugateAnswer;
}

struct arrayEight dualQuaternionMultiplication (double dualQuaternionQ[8], double dualQuaternionP[8]){

  // dual quaternion quaternionMultiplication

  struct arrayFour quaternionQScalar;
  struct arrayFour quaternionQVector;
  struct arrayFour quaternionPScalar;
  struct arrayFour quaternionPVector;
  struct arrayEight dualQuaternionQPAnswer;

  for (int i = 0 ; i<4; i++){
    quaternionQScalar.arrayCreate[i] = dualQuaternionQ[i];
    quaternionQVector.arrayCreate[i] = dualQuaternionQ[i+4];
    quaternionPScalar.arrayCreate[i] = dualQuaternionP[i];
    quaternionPVector.arrayCreate[i] = dualQuaternionP[i+4];
  }

  struct arrayFour dualQuaternionScalarQP = quaternionMultiplication(quaternionQScalar.arrayCreate,quaternionPScalar.arrayCreate);

  struct arrayFour dualQuaternionVectorQP_1 = quaternionMultiplication(quaternionQScalar.arrayCreate,quaternionPVector.arrayCreate);
  struct arrayFour dualQuaternionVectorQP_2 = quaternionMultiplication(quaternionQVector.arrayCreate,quaternionPScalar.arrayCreate);

  struct arrayFour dualQuaternionVectorQP_1PlusQP_2 = quaternionAddition(dualQuaternionVectorQP_1.arrayCreate,dualQuaternionVectorQP_2.arrayCreate);

  for (int i =0; i<4; i++){
      dualQuaternionQPAnswer.arrayCreateEight[i] = dualQuaternionScalarQP.arrayCreate[i];
      dualQuaternionQPAnswer.arrayCreateEight[i+4] = dualQuaternionVectorQP_1PlusQP_2.arrayCreate[i];
  }

  return dualQuaternionQPAnswer;

}


double * getRandom( ) {
   static double  r[3]= {0.707 , 0.707 , 0.707};
   return r;
}


int main()

{
  double *p;
  double *q;
  double pointArray[4] = {0.0, 0.0, 0.0, 10.0}; // l value of screw
  double *pointerPoint = pointArray; // cpnvert l value from  array to pointer
  int directionA[3] = {0, 0, 1};
  int directionB[3] = {1, 0, 0};
  // p = quaternion(1.414, directionA);
  struct arrayFour quaternionTwo = quaternion(1.414,directionA);
  struct arrayFour quaternionThree = quaternion(1.414,directionB);
  struct arrayEight quaternionConjugateS = createDualQuaternion(quaternionTwo.arrayCreate,quaternionThree.arrayCreate);
  // q = quaternionDualPart(p,pointerPoint);

  // double * pq = quaternionMultiplication(p,p);
  cout<<"value of dual part"<<endl;
  for ( int i = 0; i < 8; i++ ) {
     cout << "*(q + " << i << ") : ";
     cout << quaternionConjugateS.arrayCreateEight[i] << endl;
  }

  cout<<"value of dual part"<<endl;
  for ( int i = 0; i < 4; i++ ) {
     cout << "*(q + " << i << ") : ";
     cout << quaternionTwo.arrayCreate[i] << endl;
  }

  cout<<"value of dual part"<<endl;
  for ( int i = 0; i < 4; i++ ) {
     cout << "*(q + " << i << ") : ";
     cout << quaternionThree.arrayCreate[i] << endl;
  }

  double a[] = {1, 2, 3};
  double b[3] = {1, 2, 3};
  // double answer = dotMatrix(a,b);
  // cout << answer <<endl;
  return 0;

}
