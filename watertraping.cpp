#include <bits/stdc++.h>
using namespace std;

// maximum sum of subarray

// histogram area
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int left[n],right[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int area =0 ;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty()){
                right[i]=n;
            }
            else right[i]=st.top();
            st.push(i);
            area = max(heights[i]*(right[i]-left[i]-1),area);
        }
        return area;
    }
// given 2d array with input of 1 and 0 give maximum area with all ones

int maxArea(vector<vector<int>>mt,int n){
    int csum[n][n];
    for(int j=0;j<n;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(mt[i][j]==1)
            sum+=mt[i][j];
            else sum =0 ;
            csum[i][j] = sum;
        }
    }
    int area =0 ;
    for(int i=0;i<n;i++){
        vector<int>raw;
        for(int j=0;j<n;j++){
            raw.push_back(csum[i][j]);
        }
        area = max(area,largestRectangleArea(raw));
    }
    return area;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>mt;
    for(int i=0;i<n;i++){
        vector<int>raw;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            raw.push_back(temp);
        }
        mt.push_back(raw);
    }
    cout<<maxArea(mt,n);

}