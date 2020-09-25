#include <stdio.h>
#include <stdlib.h>



int main()
{

    int i,rr,m;
int odr=0,odrcpy=0,j=0,odrcpy2=0;
	float coef[600]={0},res[600]={0},c=0;


	printf("....ROUTH-HURWITZ STABILITY CRETERIA....\n");
	printf("[The absolute stability of the system can be obtained directly from the coefficients of characteristic equation.]\n");
	printf("---------------------------------------------------------------------\n\n");
above:
	printf("Enter the Order of the characteristic equation\n");
	printf("[Order must be greater than 2]\n\n");
	scanf("%d",&odr);

	if (odr<=2)
    {
         printf("Please enter the order greater than 2\n");
        goto above;
    }
	odrcpy2=odr;

	for( i=odr;i>0;i--)
	{
		printf("Enter the co-efficient of X in order : %d\t",i);
		scanf("%f",&coef[i]);
	}
	printf("Enter the constant\t\n");
	scanf("%f",&c);

	printf("\nSYSTEM EQUATION:\n\n");
	for( i=odr;i>0;i--)
	{
		printf(" %fS^%d+",coef[i],i);
	}
	printf("%f = 0",c);


	printf("\n\n\n");
	printf("tabulation:\n______________________________\n");
	printf("______________________________\n");

	if(odr%2==0) //n is even
	{
		printf("\nS^%d\t",odr);
		for( i=odr;i>0;i=(i-2))
		{
			printf(" | %f\t",coef[i]);
		}//for s^n

		printf("\n");
		for( rr=0;rr<=(15*odrcpy2);rr++)
			printf("_");


		printf("\nS^%d\t",odr-1);
		for( i=odr-1;i>0;i=(i-2))
		{
			printf(" | %f\t",coef[i]);
		}//for s^(n-1)

		printf("\n");
		for( rr=0;rr<=(15*odrcpy2);rr++)
			printf("_");
	}


		if(odr%2!=0) //n is odd
	{
		printf("\nS^%d\t",odr);
		for( i=odr;i>0;i=(i-2))
		{
			printf(" | %f\t",coef[i]);
		}//for s^n


		printf("\n");
		for( rr=0;rr<=(15*odrcpy2);rr++)
			printf("_");


		printf("\nS^%d\t",odr-1);
		for( i=odr-1;i>0;i=(i-2))
		{
			printf(" | %f\t",coef[i]);
		}//for s^(n-1)
		printf(" | %f\t",c);

		printf("\n");
		for( rr=0;rr<=(15*odrcpy2);rr++)
			printf("_");
	}






            coef[0]=c;
			int z=odr;
			int y=odr-1;

///////////////////////////first row of result//////////////////////
		for( i=odr;i>=0;i=(i-2))
		{
			res[j]=((coef[z-2]*coef[odr-1])-(coef[odr]*coef[y-2]))/coef[odr-1];
			z=z-2;
			y=y-2;
			j=j+1;
		}

	///////////////////////second row of result/////////
	j=odr;
	z=0;
    y=odr-1;
	for( i=odr-1;i>=0;i=(i-2))
		{
			res[j]=((coef[y-2]*res[0])-(coef[odr-1]*res[z+1]))/res[0];
			z=z+1;
			y=y-2;
			j=j+1;
		}


    int zz=1;
	int u=1;
	int s=1;
	int r=1;
	int q=odr;
    int p=1;
    int n=1;
    int o=odr-1;
    odrcpy = odr;
    for( i=odrcpy-3;i>=0;i--)
    {
        for( m=n;m<=o;m++)
            {
                res[((p+1)*odrcpy)+r]=((res[zz]*res[odr])-(res[s-1]*res[q+1]))/res[odr];
                r=r+1;
                n=n+1;
                q=q+1;
                zz=zz+1;
            }
            u=u+1;
            r=u;
            n=((u-1)*odrcpy)+(u-1);
            odr=((u)*odrcpy)+(u-1);
            s=((u-1)*odrcpy)+(u-1);
            q=(u)*odrcpy+(u-1);
            p=p+1;
            o=o-1;
            n=1;
            zz=((u-1)*odrcpy)+(u-1);


    }
    printf("\n\n\n");





	int aa=0,bb=-1;
	for( i=odrcpy2-2;i>=0;i--)
	{
		printf("S^%d\t",i);
		for( j=(aa*odrcpy2)+bb;j<=((aa+1)*odrcpy2)+bb;j++)
			{
				if(j<=-1)
					j=0;

				printf(" | %f\t",res[j]);
			}

		bb+=1;
		aa+=1;
		printf("\n");
		for( rr=0;rr<=(20*odrcpy2);rr++)
			printf("_");
		printf("\n");
	}



	int plus=0,minus=0;
	printf("\n\nFirst row\n\n");

	printf("\t%f\n",coef[odrcpy2]);
	printf("\t%f\n",coef[odrcpy2-1]);
	if(coef[odrcpy2]>=0)
		plus=1;
	else if(coef[odrcpy2]<0)
		minus=1;

	if(coef[odrcpy2-1]>=0)
		plus+=1;
	else if(coef[odrcpy2]<0)
		minus+=1;


	aa=0,bb=-1;
	for( i=odrcpy2-2;i>=0;i--)
	{
		j=(aa*odrcpy2)+bb;
		if(j<=-1)
			j=0;
		printf("\t%f\n",res[j]);

		bb+=1;
		aa+=1;
	}



	int situation=1;
	 aa=0,bb=-1;
	for( i=odrcpy2-2;i>=0;i--)
	{
		j=(aa*odrcpy2)+bb;
		if(j<=-1)
			j=0;


		if(res[j]>=0)
			plus+=1;
		else if(res[j]<0)
			minus+=1;
		else
			{printf("SYSTEM REQUIRES SOME SPECIAL CASE ANALYSIS\n");
			printf("TRY WITH \n\t1. EPSILON METHOD\n\t2. Reverse Coefficient Method\n");
			situation=0;
			goto last;
			break;}

		bb+=1;
		aa+=1;

	}

    if(plus==0 && minus>0)
	{printf("\nSystem is STABLE\nSystem is STABLE\n");
	situation=0;
	}
	else if(minus==0 && plus>0)
	{printf("\nSystem is STABLE\nSystem is STABLE\n");
	situation=0;
	}


	if(situation==1)
	{
	printf("\nSystem Is UNSTABLE\nSystem Is UNSTABLE\n\n");
	printf("Total number of Positive elements: %d\n",plus);
	printf("Total number of Negative elements: %d\n",minus);

	}

last:
printf("\n\nby: dvrblacktech");
int exiting=0;
scanf("%d",&exiting);
}


