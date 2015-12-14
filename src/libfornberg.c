#include "libfornberg.h"

float get_weight(int N, int m, int n, int v,float *vector)
{
    return vector[(N+1)*(N+1)*m+(N+1)*n+v];
}

void fornberg_weights(int M,int p,int *alpha,float *delta)
//Orden de la derivada
//p grado de aproximacion
//alpha el vector con los indices de los puntos donde se va a tomar la derivada, i.e. -2 -1 0 1 2 para derivadas centradas con aproximacion de 4 puntos
//delta vector con los pesos de la derivada
{
    int N=p;//Numero de puntos a tomar sin el del centro
	//int M=1;//Orden de la derivada
	//float delta[(M+1)*(N+1)*(N+1)];//movemos el índice en el orden n, v, m esto es delta[(N+1)*(N+1)*m+(N+1)*n+v]
	//delta=(float*)malloc((M+1)*(N+1)*(N+1)*sizeof(float));
	float c1, c2, c3;
	int min;
	int i,j,n,v,m; //contadores


    delta[(N+1)*(N+1)*0+(N+1)*0+0]=1;
	c1=1;
	printf("delta %d %d %d=%f\n",0,0,0,get_weight(N,0,0,0,delta));


	for( n = 1; n <= N; n++ ) {
	    c2=1;
		for( v = 0; v <= n-1; v++ ) {
		    c3=alpha[n]-alpha[v];
			c2=c2*c3;
			if( n <= M ) {
			    delta[(N+1)*(N+1)*n+(N+1)*(n-1)+v]=0;
			}
			if(n<M) min=n;
			else min=M;
			for( m = 0; m <= min; m++ ) {
			    if(m==0) delta[(N+1)*(N+1)*m+(N+1)*n+v]=(alpha[n]*get_weight(N,m,n-1,v,delta))/c3;
			    else delta[(N+1)*(N+1)*m+(N+1)*n+v]=(alpha[n]*get_weight(N,m,n-1,v,delta)-m*get_weight(N,m-1,n-1,v,delta))/c3;
			}
		}
		
		for( m = 0; m <= min; m++ ) {
			if(m==0) delta[(N+1)*(N+1)*m+(N+1)*n+n]=(c1/c2)*(-1*alpha[n-1]*get_weight(N,m,n-1,n-1,delta));
			else delta[(N+1)*(N+1)*m+(N+1)*n+n]=(c1/c2)*(m*get_weight(N,m-1,n-1,n-1,delta)-alpha[n-1]*get_weight(N,m,n-1,n-1,delta));
		}
		c1=c2;
	}

	/*for(m=0;m<M+1;m++) {
		for(n=m;n<N+1;n++) {
		    for(v=0;v<=n;v++){
				printf("valor del coeficiente para m= %d n = %d y v = %d es %f\n",m,n,v,get_weight(N,m,n,v,delta));
			}
		}
	}*/
}



