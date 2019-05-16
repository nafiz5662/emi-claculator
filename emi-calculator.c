#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct info
{
    long a,dp;
    double yi;
    long ni;
}data;
void interest(double emi,double p,double r,long ni,int i)
{
        double ipi,cpi;

         if(ni==0)
            return;
         else
         {
        ipi=p*r;
        cpi=emi-ipi;
        printf("\nInterest for Installment %d  %.2lf\n",i,ipi);
        printf("\nCapital per Installment  %d  %.2lf\n",i,cpi);
        interest(emi,p-cpi,r,ni-1,i+1);
        }



    }



int main()
{
    double emi,r,p,p1,p2,p3;
    int i=1;
    data x;
    printf("\nInput Loan Amount\n");
    scanf("%ld",&x.a);
    printf("\nInput Down Payment\n");
    scanf("%ld",&x.dp);
    printf("\nNumber Of Monthly Installment\n");
    scanf("%d",&x.ni);
    printf("\nYearly Interest\n");
    scanf("%lf",&x.yi);
    p=x.a-x.dp;
    r=x.yi/100;
    p1=pow((1+r),x.ni);
    p2=pow((1+r),x.ni);
    p3=p2-1;
    emi=(p*r*p1)/p3;
    printf("EMI IS %lf\n",emi);
    printf("\nTotal Monthly Installment %.2lf\n",emi*x.ni);
    interest(emi,p,r,x.ni,i);


}
