#include<bits/stdc++.h>
using namespace std;
#define SZ 800005
#define boost ios::sync_with_stdio(0);cin.tie(0)
 
struct node {
    int maxRoom;
    int maxRoomIdx;
    node(int a, int b): maxRoom(a), maxRoomIdx(b){};
};
 
vector<node*> tree(SZ*4, new node(0,-1));
int n, m, rooms;
 
void update(int pos, int val, int i=1, int ss=0, int se=n-1) {
    if(pos>se || pos<ss) return;
    if(ss == se) {
        tree[i] = new node(val, ss);
        return;
    }
    int mid = (ss+se)>>1;
    update(pos, val, 2*i, ss, mid);
    update(pos, val, 2*i+1, mid+1, se);
    if(tree[2*i]->maxRoom >= tree[2*i+1]->maxRoom) {
        tree[i] = tree[2*i];
    }
    else {
        tree[i] = tree[2*i+1];
    }
}
 
node* query(int &roomsNeeded, int i=1, int ss=0, int se=n-1) {
    if(ss==se && tree[i]->maxRoom>=roomsNeeded) return tree[i];
    int mid = (ss+se)>>1;
    node* left = tree[2*i];
    node* right = tree[2*i+1];
    if(left->maxRoom >= roomsNeeded) {
        return query(roomsNeeded, 2*i, ss, mid);
    }
    if(right->maxRoom >= roomsNeeded){
        return query(roomsNeeded, 2*i+1, mid+1, se);
    }
    return new node(0, -1);
}
 
 
signed main() {
    boost;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> rooms;
        update(i, rooms);
        cout<<endl;
    }
    
    for(int i=0; i<m; i++) {
        int roomsNeeded;
        cin >> roomsNeeded;
        node* hotel = query(roomsNeeded);
        cout << 1+hotel->maxRoomIdx << " ";
        update(hotel->maxRoomIdx, hotel->maxRoom-roomsNeeded);
    }
}
