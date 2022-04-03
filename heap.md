# implementation of minheap
```  c++
#include<bits/stdc++.h>
using namespace std;
class minheap
{
    public:
        vector<int> pq;
    int parent(int i)
    {
        if((i-1)/2>=0)
        {
            return (i-1)/2;
        }
        return -1;

    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    void heapifyUp(int index){
        //check if parent present
        if(parent(index)>=0){
            //check if parent is more than current
            if(pq[parent(index)]>pq[index]){
                //for max heap =>if(pq[parent(index)]<pq[index])
                int temp=pq[index];
                pq[index]=pq[parent(index)];
                pq[parent(index)]=temp;
                heapifyUp(parent(index));
            }
        }
    }
    void swap(int index1,int index2)
    {
        int temp=pq[index1];
        pq[index1]=pq[index2];
        pq[index2]=temp;
    }
    void heapifyDown(int index){
        if(left(index)<pq.size() && right(index)<pq.size()){
            if(pq[left(index)]<pq[right(index)]){
                swap(index,left(index));
                heapifyDown(left(index));
            }
            else{
                swap(index,right(index));
                heapifyDown(right(index));
            }

        }
    }

    void deletetr(){
        if(pq.size()<=0){
            cout<<"cant ";
        }
        else{
            //swap first ele with last ele then delete last ele
            pq[0]=pq[pq.size()-1];
            pq.pop_back();
            heapifyDown(0);    //index needed for recursion
        }
    }
    void insert(int num){
        pq.push_back(num);
        heapifyUp(pq.size()-1);
    }
    void peek(){
        if(pq.size()>0)
        cout<<pq[0];
        else
        cout<<"pq empty";
    }
    
};
int main()
{
    minheap pq;
    pq.insert(11);
    pq.insert(2);
    pq.insert(3);
    pq.deletetr();
    pq.insert(2);
    pq.insert(1);
    pq.peek();

}
```