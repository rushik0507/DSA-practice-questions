#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    int marks;
    int rank;
};

void bucketSort(vector<student> &nums, int n)
{
    vector<vector<student>> ranks(361);
    for (int i = 0; i < n; i++)
    {
        ranks[nums[i].marks].push_back(nums[i]);
    }
    nums.clear();
    int count;int temp=1;
    for(int i=360; i>=0 ; i--){
        int count =0 ;
        for(int j=0;j<ranks[i].size();j++){
            count++;
            ranks[i][j].rank = temp;
            nums.push_back(ranks[i][j]);
        }
        temp+=count;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<student>nums;
    for(int i=0;i<n;i++){
        student s;
        cin>>s.marks;
        nums.push_back(s);
    }
    bucketSort(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i].marks<<"->"<<nums[i].rank<<endl;
    }

}