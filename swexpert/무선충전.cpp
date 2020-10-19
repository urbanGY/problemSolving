#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b) {
                return a.second > b.second;
        }
};

int aabs(int a) {
        return a >= 0 ? a : -a;
}
int getMax(int a, int b) {
        return a > b ? a : b;
}
pair<int,int> getXY(int x, int y, int direct) {
        pair<int,int> pr = {x,y};
        if(direct == 1) {//top
                pr.first -= 1;
        }else if(direct == 2) {//right
                pr.second += 1;
        }else if(direct == 3) {//bottom
                pr.first += 1;
        }else if(direct == 4) {//left
                pr.second -= 1;
        }
        return pr;
}

void setMap(map<pair<int,int>, vector<pair<int,int> > >& xy, int x, int y, int c, int p, int idx) { // pq의 값 넣고 빼는 과정에서 제대로 동작하지 않았다. 가능하면 쉬운 자료구조로 구현하자.
        for(int i = 1; i <= 10; i++ ) {
                for(int j = 1; j <= 10; j++) {
                        if( aabs(i-x) + aabs(j-y) <= c ) {
                                pair<int,int> pr = {i,j};
                                xy[pr].push_back({idx,p});
                        }
                }
        }
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                int m, a, answer = 0;
                map<pair<int,int>, vector<pair<int,int> > > xy;
                pair<int,int> apos = {1,1}, bpos = {10,10};
                vector<pair<int,int> > alist, blist;
                scanf(" %d %d",&m,&a);
                alist.push_back(apos);
                blist.push_back(bpos);
                for(int i = 0; i < m; i++) {
                        int direct;
                        scanf(" %d",&direct);
                        apos = getXY(apos.first,apos.second,direct);
                        alist.push_back(apos);
                }
                for(int i = 0; i < m; i++) {
                        int direct;
                        scanf(" %d",&direct);
                        bpos = getXY(bpos.first,bpos.second,direct);
                        blist.push_back(bpos);
                }
                for(int i = 0; i < a; i++) {
                        int x, y, c, p;
                        scanf(" %d %d %d %d",&x,&y,&c,&p);
                        setMap(xy,y,x,c,p,i);
                }
                for(int i = 0; i <= m; i++) {
                        apos = alist[i];
                        bpos = blist[i];
                        vector<pair<int,int> > ainfo = xy[apos];
                        ainfo.push_back({-1,0});
                        vector<pair<int,int> > binfo = xy[bpos];
                        binfo.push_back({-2,0});
                        int maxtmp = 0;
                        for(auto apr : ainfo) {
                                for(auto bpr: binfo) {
                                        int tmp;
                                        if(apr.first == bpr.first) tmp = (apr.second + bpr.second) /2;
                                        else tmp = apr.second + bpr.second;
                                        if(tmp > maxtmp) maxtmp = tmp;
                                }
                        }
                        answer += maxtmp;
                }
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
