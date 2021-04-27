
/**
 *      author  : tanzidi
 *      created : Tuesday, 2021-04-27-13.07.11
 *      path    : C:\Users\USER\Desktop\RMQ.cpp
 *      link    : https://www.spoj.com/problems/RMQSQ/
**/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int mod = 1e9+7;

#define input freopen("in.txt", "r", stdin);
#define output freopen("out.txt", "w", stdout);
#define dekha(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int mx = 100000;
const int LOGmx = (int)log2(mx);
int table[LOGmx+1][mx+1];
int ara[mx+1];

void precal(int n){

    int LOG = (int)log2(n);
    for(int i=0; i<n; i++)table[0][i] = ara[i];

    for(int j=1; j<=LOG; j++){
        for(int i=0; i+(1<<j)-1 < n; i++){
            table[j][i] = min(table[j-1][i], table[j-1][i+(1<<(j-1))]);
        }
    }

}

int query(int l, int r){

    int len = (r - l) + 1;
    int LOG = (int)log2(len);

    return min(table[LOG][l], table[LOG][r-(1<<LOG)+1]);

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;cin>>n;
    for(int i=0; i<n; i++){
        cin>>ara[i];
    }
    precal(n);
    int q;cin>>q;
    while(q--){
        int l, r;cin>>l>>r;
        cout<<query(l, r)<<endl;
    }

}

/** "So which of the favors of your Lord would you deny?" (Ar-Rahman) **/
