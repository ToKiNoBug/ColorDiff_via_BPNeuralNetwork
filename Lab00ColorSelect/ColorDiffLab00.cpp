#include "mex.h"
#include <cmath>
#define M_PI 3.14159265358979323846
#define deg2rad(deg) ((deg)*M_PI/180.0)
#define rad2deg(rad) ((rad)*180.0/M_PI)
#define kL 1.0
#define kC 1.0
#define kH 1.0

#define ShowIntermedium

using namespace std;

inline double square(double x)
{
    return x*x;
}

double Lab00(const double&L1,const double&a1,const double&b1,const double&L2,const double&a2,const double&b2)
{
    double C1sab=sqrt(a1*a1+b1*b1);
    double C2sab=sqrt(a2*a2+b2*b2);
    double mCsab=(C1sab+C2sab)/2;
    double G=0.5*(1-sqrt(pow(mCsab,7)/(pow(mCsab,7)+pow(25,7))));
    double a1p=(1+G)*a1;
    double a2p=(1+G)*a2;
    double C1p=sqrt(a1p*a1p+b1*b1);
    double C2p=sqrt(a2p*a2p+b2*b2);
    double h1p,h2p;
    if(b1==0&&a1p==0)h1p=0;
    else h1p=atan2(b1,a1p);
    if(h1p<0)h1p+=2*M_PI;

    if(b2==0&&a2p==0)h2p=0;
    else h2p=atan2(b2,a2p);
    if(h2p<0)h2p+=2*M_PI;
    
    double dLp=L2-L1;
    double dCp=C2p-C1p;
    double dhp;
    if(C1p*C2p==0)
    {
        dhp=0;
    }
    else{
        if(abs(h2p-h1p)<=deg2rad(180.0))
        {
            dhp=h2p-h1p;
        }
        else if(h2p-h1p>deg2rad(180.0))
        {
            dhp=h2p-h1p-deg2rad(360.0);
        }
        else{
            dhp=h2p-h1p+deg2rad(360.0);
        }
    }

    double dHp=2*sqrt(C1p*C2p)*sin(dhp/2.0);



    double mLp=(L1+L2)/2;
    double mCp=(C1p+C2p)/2;
    double mhp;
    if(C1p*C2p==0)
    {
        mhp=(h1p+h2p);
    }
    else if(abs(h2p-h1p)<=deg2rad(180))
    {
        mhp=(h1p+h2p)/2;
    }
    else if(h1p+h2p<deg2rad(360))
    {
        mhp=(h1p+h2p+deg2rad(360))/2;
    }
    else
    {
        mhp=(h1p+h2p-deg2rad(360))/2;
    }

    double T=1-0.17*cos(mhp-deg2rad(30))+0.24*cos(2*mhp)+0.32*cos(3*mhp+deg2rad(6))-0.20*cos(4*mhp-deg2rad(63));

    double dTheta=deg2rad(30)*exp(-square((mhp-deg2rad(275))/deg2rad(25)));

    double RC=2*sqrt(pow(mCp,7)/(pow(25,7)+pow(mCp,7)));

    double SL=1+0.015*square(mLp-50)/sqrt(20+square(mLp-50));

    double SC=1+0.045*mCp;

    double SH=1+0.015*mCp*T;

    double RT=-RC*sin(2*dTheta);

    double Diffsquare=square(dLp/SL/kL)+square(dCp/SC/kC)+square(dHp/SH/kH)+RT*(dCp/SC/kC)*(dHp/SH/kH);

#ifdef ShowIntermedium
    printf("%s%lf\n","a1p=",a1p);    
    printf("%s%lf\n","a2p=",a2p);

    printf("%s%lf\n","C1p=",C1p);    
    printf("%s%lf\n","C2p=",C2p);

    printf("%s%lf\n","h1p=",rad2deg(h1p));    
    printf("%s%lf\n","h2p=",rad2deg(h2p));

    printf("%s%lf\n","mhp=",rad2deg(mhp));
    printf("%s%lf\n","G=",G);
    printf("%s%lf\n","T=",T);
    printf("%s%lf\n","SL=",SL);
    printf("%s%lf\n","SC=",SC);
    printf("%s%lf\n","SH=",SH);
    printf("%s%lf\n","RT=",RT);

#endif

    return sqrt(Diffsquare);

}

void mexFunction(int outC,mxArray *outV[],int inC,const mxArray *inV[])
{
    if(inC<6)return;
    //if(outC<=0)return;
    //if(!mxIsDouble(inV[0]))mexErrMsgTxt("Input matrix type error, You should only input float64(double) matrix");
    size_t N=mxGetM(inV[0])*mxGetN(inV[0]);
    outV[0]=mxCreateNumericMatrix(mxGetM(inV[0]),mxGetN(inV[0]),mxDOUBLE_CLASS,mxREAL);

    double *outPtr=mxGetPr(outV[0]);
    const double *L1=mxGetPr(inV[0]),*a1=mxGetPr(inV[1]),*b1=mxGetPr(inV[2]);
    const double *L2=mxGetPr(inV[3]),*a2=mxGetPr(inV[4]),*b2=mxGetPr(inV[5]);

    for(size_t i=0;i<N;i++)
    {
        outPtr[i]=Lab00(L1[i],a1[i],b1[i],L2[i],a2[i],b2[i]);
    }
    return;

}