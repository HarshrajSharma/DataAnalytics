// Write a program in C language to Cluster a set of two dimensional Data points , using K-Means Clustering Algorithm. Consider fixed initial centroids, and value of k =2.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct st
{//created a structure to store data of points and its cluster id
float x;
float y;
int id;
};
typedef struct st cluster;//Structure is typedef to cluster
float dist(float x, float y, float cx, float cy)//x and y are data points where as cx and cy are centroids
{
float temp = (cx - x) * (cx - x) + (cy - y) * (cy - y);
return temp;
}
void clusterMean(struct st data[30], float temp[4])
{
int count0 = 0, count1 = 0;
float mean0x = 0, mean0y = 0, mean1x = 0, mean1y = 0;
for (int i = 0; i < 7; i++)//here we have seven points
{
if (data[i].id == 0)//the points having cluster id 0 are taken
{
mean0x += data[i].x;//x co-ordinates of id 0 are summed
mean0y += data[i].y;//y co-ordinates of id 0 are summed
count0++;//count of id 0 is incremented
}
if (data[i].id == 1)//the points having cluster id 0 are taken
{
mean1x += data[i].x;//x co-ordinates of id 1 are summed
mean1y += data[i].y;//y co-ordinates of id 1 are summed
count1++;//count of id 1 is incremented
}
}
temp[0] = mean0x / count0;//mean of both 0 and 1 ids are calculated and stored to temp array
temp[1] = mean0y / count0;
temp[2] = mean1x / count1;
temp[3] = mean1y / count1;
}
int main()
{
int max = 10;
int n;
printf("Enter number of points :- ");
scanf("%d", &n);
cluster cent0, cent1;
cent0.x = 1.0;
cent0.y = 1.0;
cent1.x = 5.0;
cent1.y = 7.0;
cluster data[30];//a data array is taken
printf("Enter data :- \n");
for (int i = 0; i < n; i++)
scanf("%f%f", &data[i].x, &data[i].y);
struct st prev1;//prev1 is taken to compare
prev1.x = -1;
prev1.y = -1;
while (max > 0 && (prev1.x != cent0.x && prev1.y != cent0.y))//until the iterations are completed or previous value of centroid is not equal to current value
{
for (int i = 0; i < n; i++)//all data items are taken
{
if (dist(data[i].x, data[i].y, cent0.x, cent0.y) > dist(data[i].x, data[i].y, cent1.x, cent1.y))// if dist of a point from its centroid is greater than other centroid
{
data[i].id = 1;//the point is transfereed its id 1
}
else
{
data[i].id = 0;//else 0
}
}
max--;//for each iteration max is decremented
float temp[4];
clusterMean(data, temp);//mean function is called
prev1.x = cent0.x;//centroid value is assigen to prev1
prev1.y = cent0.y;
cent0.x = temp[0];
cent0.y = temp[1];
cent1.x = temp[2];
cent1.y = temp[3];
printf("Mean1[%.1f,%.1f] and Mean2[%.1f.%.1f]\n", temp[0], temp[1], temp[2], temp[3]);
}
}