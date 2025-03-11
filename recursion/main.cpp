#include<iostream>
#include<vector>



using namespace std;

//normal recursion
/*

*/

const vector<int> v{1,2,3,4,5,6,7};
int fact(int n)
{
    if(n==1) 
    {return 1;}
    return n*fact(n-1);
}

void print(int i)
{
    if(i<0)return;
    //cout<<v[i]; reverse
    print(i-1);
    cout<<v[i]; //normal

}
int main()
{



   int p =  fact(6);
   std::cout<<p<<endl;
   print(v.size()-1);


}