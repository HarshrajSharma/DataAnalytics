// #2) Apply Elbow method to calculate the optimum value of k. Modify your program to vary the number of clusters, k, from 2 to 10. For each k calculate the sum squared error value. Find the optimum k value for which lowest error is achieved


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdlib.h>
#include<stdbool.h>
int dist(int x1,int y1,int x2,int y2)
{
return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
struct st
{
float x,y;
int cid,pid;
};
int error(struct st node[],struct st centroid[],int n)
{
int sum=0;
for(int i=0;i<n;i++)
{
sum+=(node[i].x- centroid[node[i].cid].x)*(node[i].x- centroid[node[i].cid].x)+(node[i].y -
centroid[node[i].cid].y)*(node[i].y - centroid[node[i].cid].y);
}
return sum;
}
void findCentroid(struct st node[],float cent[][2],int n,int k)
{
int count[k];
for(int i=0;i<k;i++)
{
count[i]=0;
cent[i][0]=0;
cent[i][1]=0;
}
for(int i=0;i<n;i++)
{
cent[node[i].cid][0]+=node[i].x;
cent[node[i].cid][1]+=node[i].y;
count[node[i].cid]++;
}
for(int i=0;i<k;i++)
{
if(count[i]==0)
continue;
cent[i][0] = cent[i][0]/(float)(count[i]);
cent[i][1] = cent[i][1]/(float)(count[i]);
}
for(int i=0;i<k;i++)
printf("\n%f %f\n",cent[i][0],cent[i][1]);
}
int main()
{
int n;
printf("Enter the number of data points\n");
scanf("%d",&n);
struct st node[n];
printf("Enter the data points\n");
float x,y;
for(int i=0;i<n;i++)
{
scanf("%f%f",&node[i].x,&node[i].y);
node[i].pid = i; node[i].cid = -1;
}
int instance=-1,minm = 1000000;
for(int k=2;k<=10;k++)
{
printf("\nthe value of k %d\n",k);
struct st centroid[k];
printf("Enter %d centroids\n",k);
for(int i=0;i<k;i++)
{
scanf("%f%f",&centroid[i].x,&centroid[i].y);
centroid[i].cid = i;
}
int ind=0;
float ans[10000][2];
int iter=0;
while(iter<10)
{
for(int i=0;i<n;i++)
{
int mind=1000000000,cent = -1;
for(int j=0;j<k;j++)
{
int d = dist(node[i].x,node[i].y,centroid[j].x,centroid[j].y);
if(d<mind)
{
mind = d;
cent = j;
}
}
node[i].cid = cent;
}
float newcent[k][2];
findCentroid(node,newcent,n,k);
bool flag = true;
printf("\nCentroids\n");
for(int i=0;i<k;i++)
{
printf("\n id:%d x= %f y = %f\n",i,centroid[i].x,centroid[i].y);
if(centroid[i].x == newcent[i][0]||centroid[i].y == newcent[i][1])
flag = false;
centroid[i].x = newcent[i][0];
centroid[i].y = newcent[i][1];
}
if(!flag){
iter++;
break;
}
iter++;
}
int err = error(node,centroid,n);
if(minm>err)
{
minm = err;
instance = k;
}
printf("\nNo of iterations for instance %d is %d",k,iter);
}
printf("\nwe got minimum error in the %d that is the optimum value for k\n",instance);
return 0;
}