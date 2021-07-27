#include "mex.h"
#include <cmath>

void mexFunction(int outC,mxArray *outV[],int inC,const mxArray *inV[])
{
    if(inC<2)return;
    //if(outC<=0)return;
    //if(!mxIsDouble(inV[0]))mexErrMsgTxt("Input matrix type error, You should only input float64(double) matrix");
    size_t N=mxGetM(inV[0])*mxGetN(inV[0]);
    outV[0]=mxCreateNumericMatrix(mxGetM(inV[0]),mxGetN(inV[0]),mxDOUBLE_CLASS,mxREAL);

    double *outPtr=mxGetPr(outV[0]);
    const double *inPtry=mxGetPr(inV[0]),*inPtrx=mxGetPr(inV[1]);

    for(size_t i=0;i<N;i++)
    {
        outPtr[i]=atan2(inPtry[i],inPtrx[i]);
    }
    return;

}