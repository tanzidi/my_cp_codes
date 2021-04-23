
/**
 *      author  : tanzidi
 *      created : Friday, 2021-04-23-20.21.05
 *      path    : C:\Users\USER\Desktop\MO's algo.cpp
**/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int mod = 1e9+7;

#define input freopen("in.txt", "r", stdin);
#define output freopen("out.txt", "w", stdout);
#define dekha(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct query{

    int l, r, idx;

};

bool cmp(query a, query b){

    return a.r < b.r;

}

int F[100010], FofF[100010];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, q;scanf("%d%d", &n, &q);
    int ara[n];

    for(int i=0; i<n; i++)scanf("%d", &ara[i]);

    int sq = ceil(sqrt(n));

    vector<query> blocks[sq];
    int ans[q];

    for(int i=0; i<q; i++){

        int L, R;scanf("%d%d", &L, &R);
        int pos = floor(L*1.0 / sq);

        query a;
        a.l = L, a.r = R, a.idx = i;

        blocks[pos].push_back(a);

    }

    int mx = 0;
    int L = 0, R = -1;
    for(int i=0; i<sq; i++){

        sort(blocks[i].begin(), blocks[i].end(), cmp);
        int sz = blocks[i].size();

        for(int j=0; j<sz; j++){

            query a = blocks[i][j];
            //cout<<dekha(a.l)<<" "<<dekha(a.r)<<endl;

            while(L > a.l){

                L--;
                int agerFreq = F[ara[L]];
                F[ara[L]]++;
                int bortomanFreq = F[ara[L]];
                FofF[agerFreq]--;
                FofF[bortomanFreq]++;
                if(bortomanFreq > mx)mx = bortomanFreq;
                //cout<<dekha(L)<<endl;

            }

            while(R < a.r){

                R++;
                int agerFreq = F[ara[R]];
                F[ara[R]]++;
                int bortomanFreq = F[ara[R]];
                FofF[agerFreq]--;
                FofF[bortomanFreq]++;
                if(bortomanFreq > mx)mx = bortomanFreq;
                //cout<<dekha(R)<<endl;

            }

            while(L < a.l){

                int agerFreq = F[ara[L]];
                F[ara[L]]--;
                int bortomanFreq = F[ara[L]];
                FofF[agerFreq]--;
                FofF[bortomanFreq]++;
                if(bortomanFreq < mx){
                    while(FofF[mx] == 0){
                        mx--;
                    }
                }
                L++;
                //cout<<dekha(L)<<endl;

            }

            while(R > a.r){

                int agerFreq = F[ara[R]];
                F[ara[R]]--;
                int bortomanFreq = F[ara[R]];
                FofF[agerFreq]--;
                FofF[bortomanFreq]++;
                if(bortomanFreq < mx){
                    while(FofF[mx] == 0){
                        mx--;
                    }
                }
                R--;
                //cout<<dekha(R)<<endl;
            }
//            cout<<"===="<<endl;
//            for(int i=1; i<=10; i++)cout<<dekha(i)<<" "<<dekha(F[i])<<" "<<dekha(FofF[i])<<endl;
//            cout<<"===="<<endl;
            ans[a.idx] = mx;

        }
    }
    for(int i=0; i<q; i++){
        printf("%d\n", ans[i]);
    }

}

/** "So which of the favors of your Lord would you deny?" (Ar-Rahman) **/
