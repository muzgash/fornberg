#include "libfornberg.h"

int main(int argc, char *argv[])
{
    float *w;
	int i,j,m,n,v,M=1,p=4;
    int alpha[p+1];

	w=(float*)malloc((M+1)*(p+1)*(p+1)*sizeof(float));

	for( i = 0; i <= p; i++) {
	    alpha[i]=i;
	}

	fornberg_weights(M,p,alpha,w);

	for(m=0;m<M+1;m++) {
		for(n=m;n<p+1;n++) {
		    for(v=0;v<=n;v++){
				//printf("valor del coeficiente para m= %d n = %d y v = %d es %f\n",m,n,v);
				printf("valor del coeficiente para m= %d n = %d y v = %d es %f\n",m,n,v,get_weight(p,m,n,v,w));
			}
		}
	}

    return 0;
}
