#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int n;
struct datapt
{
	float x;
	float y;
	float z;
	int cid;
};
void centroid(float mew[n][2],struct datapt data[n],struct datapt *centroid,float g,int j)
{
	for(int k=0;k<3;k++)
	{
		float num=0,den=0,m;
		for(int i=0;i<n;i++)
		{
			if(k==0)
				m=data[i].x;
			else if(k==1)
				m=data[i].y;
			else
				m=data[i].z;
			num+=pow(mew[i][j],g)*m;
			den+=pow(mew[i][j],g);
		}
		if(k==0)
			centroid->x=num/den;
		else if(k==1)
			centroid->y=num/den;
		else
			centroid->z=num/den;
	}
}
float distance(struct datapt datapoint,struct datapt cent)
{
	float cx=cent.x;
	float cy=cent.y;
	float cz=cent.z;
	float dx=datapoint.x;
	float dy=datapoint.y;
	float dz=datapoint.z;
	float d=sqrt(pow(cx-dx,2)+pow(cy-dy,2)+pow(cz-dz,2));
}
int main()
{
	int c;
	float g;
	printf("\n Enter number of clusters c \n");
	scanf("%d",&c);
	printf("\n Enter level of fuzziness g \n");
	scanf("%f",&g);
	printf("\n Enter number of data points n \n");
	scanf("%d",&n);
	struct datapt data[n];
	float mew[n][2];
	//srand(time(0));
	printf("Enter mew \n");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&mew[i][0]);
		scanf("%f",&mew[i][1]);
		/*float k=((float)rand()/((float)RAND_MAX));
		int r=(int)(k*10000);
		mew[i][0]=(float)r/10000;
		mew[i][1]=1-mew[i][0];*/
		/*scanf("%f",mew[i][0]);0.431538
0.568462
0.415384
0.584616
0.509643
0.490357
0.469850
0.530150
0.189164

		scanf("%f",mew[i][1]);*/
	}
	for(int i=0;i<n;i++)
	{
		printf("%f ",mew[i][0]);
		printf("%f \n",mew[i][1]);
	}
	float num,den;
	struct datapt centroid1;
	struct datapt centroid2;
	for(int i=0;i<n;i++)
	{
		printf("\n Enter data for point %d \n",i+1);
		scanf("%f",&data[i].x);
		scanf("%f",&data[i].y);
		scanf("%f",&data[i].z);
	}
	centroid(mew,data,&centroid1,g,0);
	centroid(mew,data,&centroid2,g,1);
	printf("\n Centroid 1 : %f %f %f \n",centroid1.x,centroid1.y,centroid1.z);
	printf("\n Centroid 2 : %f %f %f \n",centroid2.x,centroid2.y,centroid2.z);
	for(int a=1;a<=5;a++)
	{
		for(int i=0;i<n;i++)
		{
			float d1=distance(data[i],centroid1);
			float d2=distance(data[i],centroid2);
			if(d1==0)
			{	
				mew[i][0]=1;
				mew[i][1]=0;
			}
			else
			{
				mew[i][0]=1/(pow(d1/d2,2/g-1)+1);
				mew[i][1]=1-mew[i][0];
			}
			if(mew[i][0]>mew[i][1])
				data[i].cid=1;
			else
				data[i].cid=2;
		}
	}
	printf("Membership matrix : \n");
	for(int i=0;i<n;i++)
		printf("%f %f \n",mew[i][0],mew[i][1]);
	for(int i=0;i<n;i++)
		printf("Data point : %d, x: %f, y: %f, z: %f, cid: %d \n",i+1,data[i].x,data[i].y,data[i].z,data[i].cid);
}

	
	
