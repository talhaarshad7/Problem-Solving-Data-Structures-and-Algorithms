#include<iostream>
using namespace std;
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input)
{
    vector<int> output;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<input.size();i++)
    {
        vector<int>* p=input[i];
        for(int j=0;j<p->size();j++)
        pq.push(p->at(j));
    }
    while(!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}

