#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node {
        int x;
        int y;
        int count;
        int direct;
        node(int x, int y, int count, int direct)
                : x(x), y(y), count(count), direct(direct) {
        }
};

int n,M,k;

int oppo(int direct) {
        if(direct == 1) return 2;
        if(direct == 2) return 1;
        if(direct == 3) return 4;
        if(direct == 4) return 3;
}

void move(node& elem) {
        int x = elem.x, y = elem.y, count = elem.count, direct = elem.direct;
        //cout<<"before : "<<x<<" , "<<y<<" , "<<count<<" , "<<direct<<endl;
        if(direct == 1) x -= 1;
        else if(direct == 4) y += 1;
        else if(direct == 2) x += 1;
        else y -= 1;

        if(x <= 0 || y <= 0 || x >= n-1 || y >= n-1) {
                direct = oppo(direct);
                count /= 2;
        }
        //cout<<"after : "<<x<<" , "<<y<<" , "<<count<<" , "<<direct<<endl;
        elem.x = x;
        elem.y = y;
        elem.count = count;
        elem.direct = direct;
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                int answer = 0;
                scanf(" %d %d %d",&n,&M,&k);
                vector<node> candidate;
                for(int i = 0; i < k; i++) {
                        int x, y, count, direct;
                        scanf(" %d %d %d %d",&x,&y,&count,&direct);
                        candidate.push_back(node(x,y,count,direct));
                }
                for(int i = 1; i <= M; i++) {
                        map<pair<int,int>, vector<node> > m;
                        while(!candidate.empty()) {
                                node elem = candidate.back();
//                cout<<elem.x<<" , "<<elem.y<<" -> ";
                                move(elem);
//                cout<<elem.x<<" , "<<elem.y<<endl;
                                m[{elem.x,elem.y}].push_back(elem);
                                candidate.pop_back();
                        }
                        for(auto pos : m) {
                                if(pos.second.size() > 1) {
                                        vector<node> tmp = pos.second;
                                        int x = pos.first.first, y = pos.first.second;
                                        int maxCnt = tmp[0].count, maxDirect = tmp[0].direct;
                                        int sum = 0;
                                        for(auto& val : tmp) {
                                                sum += val.count;
                                                if(val.count > maxCnt) {
                                                        maxCnt = val.count;
                                                        maxDirect = val.direct;
                                                }
                                        }
                                        candidate.push_back(node(x,y,sum,maxDirect));
                                }else {
                                        candidate.push_back(pos.second[0]);
                                }
                        }
                        /*
                           for(int i = 0 ; i < candidate.size() ; i++) {
                            cout<<candidate[i].x<<" , "<<candidate[i].y<<" ,"<<candidate[i].count<<" , "<<candidate[i].direct<<endl;
                           }
                           cout<<endl;
                         */
                }
                for(auto& elem : candidate) {
                        answer += elem.count;
                }
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
