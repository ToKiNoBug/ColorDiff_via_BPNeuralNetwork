#include <iostream>
#include "D:/eigen-3.3.9/Eigen/Dense"
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
using namespace Eigen;

Matrix<float,13,3> IW;
Matrix<float,3,13> LW;
Matrix<float,13,1> Ib;
Vector3f Lb(21.4799,5.3802,75.2749);

VectorXf logsig(VectorXf x)
{
	return 1.0/(1.0+(-x.array()).exp());
}

void RGB2Lab(float R,float G,float B,float&L,float&a,float&b)
{
	Vector3f Color(R,G,B);
	Vector3f Lab=logsig(LW*logsig(IW*Color+Ib)+Lb);
	L=Lab(0);a=Lab(1);b=Lab(2);
	
}

int main(int argc, char** argv) {
IW<<2.4671,-3.7772,0.6287,
0.8596,1.7352,-1.8163,
0.4733,-1.5772,0.3087,
-0.2016,1.1063,-0.4235,
0.5327,0.5717,-1.5390,
0.8550,-1.6208,0.8947,
-0.5830,-0.0577,0.2519,
-1.1034,-3.9844,-0.1268,
-0.4751,-0.3544,1.1623,
-0.3358,0.5890,0.0742,
0.3094,-0.1850,-0.2594,
0.4179,-1.2258,0.5612,
-3.8610,-5.9788,-2.5854;	
cout<<IW<<endl;

LW<<-0.2056,-1.1825,-3.7045,4.6858,3.2195,1.2343,-4.0729,-10.4762,5.7097,-12.0603,-6.0346,0.1088,-1.7614,
1.3014,0.1538,12.9982,-30.8843,1.9304,-5.2426,-17.2415,-0.2167,6.2688,27.2889,-2.2485,-20.0248,-0.1025,
-1.2749,5.6982,-4.7196,-6.5988,-15.8069,-1.3181,-6.4218,0.0690,-26.9648,-36.2279,-35.2607,-5.4404,-0.0642;

cout<<LW<<endl;

Ib<<-6.6803,
-4.9091,
-1.2176,
-1.5432,
1.4075,
-1.5569,
0.3809,
7.4756,
-1.2459,
1.5167,
-0.1532,
1.3491,
-11.3155;

cout<<Ib<<endl;

cout<<Lb<<endl;


float LAB[3];
RGB2Lab(1,1,1,LAB[0],LAB[1],LAB[2]);
cout<<LAB[0]<<"     "<<LAB[1]<<"     "<<LAB[2];

	return 0;
}
