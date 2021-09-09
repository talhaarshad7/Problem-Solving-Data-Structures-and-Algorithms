using namespace std;
#include<vector>
class MaxPriorityQueue
{
    vector<int> pq;
    MaxPriorityQueue()
    {}
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getMax()
    {
        if(isEmpty())
        return 0;
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int ci=pq.size()-1;
        while(ci>0)
        {
            int pi=(ci-1)/2;
            if(pq[pi]<pq[ci])
            {
                int temp=pq[pi];
                pq[pi]=pq[ci];
                pq[ci]=temp;
            }
            else
            break;
            ci=pi;
        }
    }
    int removeMax()
    {
        int min=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
        int lci=2*pi+1;
        int rci=2*pi+2;
        while(lci<pq.size())
        {
            int mi=pi;
            if(pq[mi]<pq[lci])
            mi=lci;
            if(rci<pq.size()&&pq[mi]<pq[rci])
            mi=rci;
            if(mi==pi)
            break;
            int temp=pq[mi];
            pq[mi]=pq[pi];
            pq[pi]=temp;
            pi=mi;
            lci=2*pi+1;
            rci=2*pi+2;
        }
        return min;
    }
    
};