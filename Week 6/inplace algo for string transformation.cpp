#include<bits/stdc++.h>
using namespace std;

void swap(char*a,char*b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(char* str,int low,int high)
{
    while(low<high)
    {
        swap(&str[low],&str[high]);
        low++;
        high--;
    }
}

void cycleleader(char* str,int shift,int len)
{
    int j;
    char item;
    
    for(int i=1;i<len;i*=3)
    {
        j=i;
        
        item=str[j+shift];
        do{
            if(j & 1)
            j=len/2 + j/2;
            else
            j=j/2;
            
            swap(&str[j+shift],&item);
        }while(j!=i);
    }
}

void inplacetransform(char * str)
{
    int k,len;
    int lenremaining=strlen(str);
    int shift=0;
    
    while(lenremaining)
    {
        k=0;
        while(pow(3,k)+1 <= lenremaining)
        k++;
        
        len=pow(3,k-1)+1;
        
        lenremaining-=len;
        
        cycleleader(str,shift,len);
        
        reverse(str,shift/2,shift-1);
        
        reverse(str,shift,shift + len/2 -1);
        
        reverse(str,shift/2,shift +len/2 -1);
        
        shift+=len;
    }
}

int main()
{
    char s[]="a1b2c3d4e5f6g7h8i9";
    inplacetransform(s);
    cout<<s;
}
