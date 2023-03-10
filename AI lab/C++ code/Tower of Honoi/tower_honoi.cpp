#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char src,char aux,char des)
{
    if( n == 1)
    {
        cout<<"Move disk from - "<<n<<" from "<<src<<"to "<<des<<endl;
         return;
    }

    TOH(n - 1 ,aux ,src ,des );
     cout<<"Move disk from - "<<n<<" from "<<src<<"to "<<des<<endl;
    TOH(n - 1 ,des , src ,aux );
}
int main()
{
    int n;
    cout<< "Enter the disk ";
    cin>>n;
    TOH (n,'A','B','C');
    return 0;
}
