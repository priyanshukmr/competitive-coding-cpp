/*
Problem: 

Given a matrix of m rows and n columns, with each matrix value 0 or 1 and an integer k:
Find minimum number of jumps required to reach (m-1,n-1) from (0,0)
Grid marked as 1 are blocked and you cannot jump over it.
Jumpsize <= k.

*/

#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define SZ 800005
#define MAXX 1000000000000000
#define boost ios::sync_with_stdio(0);cin.tie(0)
#define fi first
#define se second
#define vec vector

int output;

bool valid(int i, int j, int m, int n, vec<vec<int>> matrix) {
    return i>=0 && i<m && j>=0 && j<n && matrix[i][j]==0;
}

int minSteps(vec<vec<int>> matrix, int k){
    int m = matrix.size();
    int n = matrix[0].size();
    vec<vec<int>> dist(m, vec<int> (n, INT_MAX));
    dist[0][0]=0;
    
    priority_queue< pair<int, pair<int,int>> > pq;
    pq.push({0, {0,0}});
    
    while(pq.size()>0) {
        pair<int, pair<int,int>> top = pq.top();
        pq.pop();
        int i = top.second.first;
        int j = top.second.second;
        
        // top
        for(int jump=0; jump<=k; jump++) {
            int ni = i-jump;
            int nj=j;
            if(!valid(ni,nj,m,n,matrix)) break;
            if(dist[ni][nj] > dist[i][j]+1) {
                dist[ni][nj] = dist[i][j]+1;
                pq.push({-dist[ni][nj], {ni, nj}});
            }
        }
        // right
        for(int jump=0; jump<=k; jump++) {
            int ni = i;
            int nj = j+jump;
            if(!valid(ni,nj,m,n,matrix)) break;
            if(dist[ni][nj] > dist[i][j]+1) {
                dist[ni][nj] = dist[i][j]+1;
                pq.push({-dist[ni][nj], {ni, nj}});
            }
        }
        // bottom
        for(int jump=0; jump<=k; jump++) {
            int ni = i+jump;
            int nj = j;
            if(!valid(ni,nj,m,n,matrix)) break;
            if(dist[ni][nj] > dist[i][j]+1) {
                dist[ni][nj] = dist[i][j]+1;
                pq.push({-dist[ni][nj], {ni, nj}});
            }
        }
        // left
        for(int jump=0; jump<=k; jump++) {
            int ni = i;
            int nj = j-jump;
            if(!valid(ni,nj,m,n,matrix)) break;
            if(dist[ni][nj] > dist[i][j]+1) {
                dist[ni][nj] = dist[i][j]+1;
                pq.push({-dist[ni][nj], {ni, nj}});
            }
        }
    }
    return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];
}
 
signed main() {
    boost;    
    /*
     t1
     k=1
     [0, 0]
     [1, 0]
     ans=2
    */
    vec<vec<int>> t1;
    t1.push_back({0,0});
    t1.push_back({1,0});
    output = minSteps(t1, 1);
    cout << (output==2 ? "Passed(1)" : "failed: expected 2, found "+to_string(output)) << endl;
    
    /*
     t2
     k=2
     [0, 1]
     [1, 0]
     ans=-1
    */
    
    vec<vec<int>> t2;
    t2.push_back({0,1});
    t2.push_back({1,0});
    output = minSteps(t2, 2);
    cout << (output==-1 ? "Passed(2)" : "Failed: expected -1, found "+to_string(output)) << endl;
    
    /*
     t3
     k=2
     [0, 0, 0]
     [1, 1, 0]
     [0, 0, 0]
     [0, 1, 1]
     [0, 0, 0]
     ans=5
    */
    
    vec<vec<int>> t3;
    t3.push_back({0,0,0});
    t3.push_back({1,1,0});
    t3.push_back({0,0,0});
    t3.push_back({0,1,1});
    t3.push_back({0,0,0});
    output = minSteps(t3, 2);
    cout << (output==5 ? "Passed(3)" : "Failed: expected 5, found "+to_string(output)) << endl;
    
    /*
     t4
     k=100
     [0, 0, 0]
     [1, 1, 0]
     [0, 0, 0]
     [0, 1, 1]
     [0, 0, 0]
     ans=5
    */
    
    vec<vec<int>> t4;
    t4.push_back({0,0,0});
    t4.push_back({1,1,0});
    t4.push_back({0,0,0});
    t4.push_back({0,1,1});
    t4.push_back({0,0,0});
    output = minSteps(t4, 100);
    cout << (output==5 ? "Passed(4)" : "Failed: expected 5, found "+to_string(output)) << endl;
    
    /*
     t5
     k=5
     [0, 0, 0, 1]
     [0, 0, 0, 0]
     [0, 0, 1, 0]
     [0, 0, 1, 1]
     [1, 0, 0, 0]
     ans=3
    */
    
    vec<vec<int>> t5;
    t5.push_back({0,0,0,1});
    t5.push_back({0,0,0,0});
    t5.push_back({0,0,1,0});
    t5.push_back({0,0,1,1});
    t5.push_back({1,0,0,0});
    output = minSteps(t5, 100);
    cout << (output==3 ? "Passed(5)" : "Failed: expected 3, found "+to_string(output)) << endl;
    
}
