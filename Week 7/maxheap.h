using namespace std;


class maxheap
{
    int capacity;
    
    public:
    int*arr,heapsize;
           maxheap(int cap){
               heapsize=0;
               capacity=cap;
               arr=new int[cap];
           }
           
           void maxheapify(int);
           
           int parent(int i){return (i-1)/2;}
           int left(int i){return 2*i +1;}
           int right(int i){return 2*i +2;}
           
           int peek(){
               if(heapsize==0)
               return -1;
               else return arr[0];
           }
           
           void increase(int k,int val);
           int extractmax();
           
           void insert(int k);
           
           void deletekey(int i);
           
};

void maxheap::insert(int k)
{
    if(heapsize==capacity)
    {
        cout<<"\nOverflow";
        return;
    }
    
    heapsize++;
    int i=heapsize-1;
    arr[i]=k;
    
    while(i!=0 && arr[parent(i)]<arr[i])
    {
        swap(&arr[parent(i)],&arr[i]);
        i=parent(i);
    }
}

void maxheap::maxheapify(int i)
{
    while(left(i)<heapsize)
    {
        int smallest=i;
        if(arr[left(i)]>arr[i])
            smallest=left(i);
        if(right(i)<heapsize && arr[right(i)]>arr[smallest])
            smallest=right(i);
        if(smallest!=i)
        {
            swap(&arr[smallest],&arr[i]);
            i=smallest;
        }
        else if(smallest==i)
        break;
    }
}

int maxheap::extractmax()
{
    if(heapsize==0)
    {
        cout<<"\nEmpty";
        return INT_MAX;
    }
    
    if(heapsize==1)
    {
        heapsize--;
        return arr[0];
    }
    
    else
    {
        int temp=arr[0];
        arr[0]=arr[heapsize-1];
        heapsize--;
        maxheapify(0);
        
        return temp;
    }
}

void maxheap::increase(int k,int val)
{
    if(val<=k)
    return;
    
    arr[k]=val;
    while(k>0 && arr[parent(k)]<arr[k])
    {
        swap(&arr[k],&arr[parent(k)]);
        k=parent(k);
    }
}

void maxheap::deletekey(int i)
{
    increase(i,INT_MAX);
    extractmax();
}
