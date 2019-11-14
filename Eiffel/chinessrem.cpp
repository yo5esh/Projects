#include<iostream>
#include<fstream>

using namespace std;
int ModInverse(int a , int m)
{
      a = a%m;
   for(int x = 1;x<m;x++)
  if(((a*x)%m )== 1) 
   {  
         return x;
    }  else 
    {
        cout<<"INVALID"<<endl;
    }
}

int findMinX( int num[], int rem[], int k)
{
     int prod = 1;   // a variable 
   for(int i=0;i<k;i++)
        prod *= num[i];    // m = m1*m2*m3*m4*........*mn

   int result = 0;
for(int j =0;j<k;j++)
{
       int y = prod/num[j];
     // num  = m[i];
  
       if( (ModInverse(  y,num[j]))>0)
    {
        result = result + rem[j]*ModInverse(  y,num[j])*y; 

     } else  
     {
         cout<<"INVALID"<<endl;
      } 
}

      return result;
}

int main() {
   
         ifstream infile;
         infile.open("input.txt");
     
          int n;
         infile>>n;
         int num[n];
         int rem[n];
      
	for (int i = 0; i < n; i++)
	             infile>>num[i];
	for (int j = 0; j < n; j ++)
	             infile>>rem[j];
    infile.close();

     ofstream myfile;
     myfile.open("output.txt");
     myfile<<findMinX(num, rem, n);
     myfile.close();
  
    return 0; 

}

