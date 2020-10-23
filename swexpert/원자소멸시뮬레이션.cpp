#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
struct node {
        int x;
        int y;
        int direct;
        int k;
        node(int x, int y, int direct, int k)
                : x(x), y(y), direct(direct), k(k) {
        }
};

int aabs(int a) {
        return a > 0 ? a : -a;
}
int oppo(int direct) {
        if(direct == 0) return 1;
        if(direct == 1) return 0;
        if(direct == 2) return 3;
        if(direct == 3) return 2;
}
int n;
vector<bool> check;
vector<bool> seq;
vector<vector< int > > m;

void find(node& cur, node& other, int curIdx, int otherIdx) {
        int curDirect = cur.direct;
        int x = cur.x, y = cur.y;
        bool sameDist = aabs(cur.x - other.x) == aabs(cur.y - other.y) ? true : false; // 두 원소간의 x, y 의 거리가 같은 경우를 판단하기 위함이다.
        bool flag = false;
        if(curDirect == 0) {
                if(cur.direct == oppo(other.direct) && cur.x == other.x && cur.y < other.y) flag = true; // 같은 수직선에 있는 경우 위 x,y 거리로 참을 판단할 수 없다. 이 경우를 위한 케이스를 따로 구성해줘야한다.
                else if(sameDist && other.direct == 3 && other.x < x && other.y > y) flag = true;
                else if(sameDist && other.direct == 2 && other.x > x && other.y > y) flag = true;
        }else if(curDirect == 1) {
                if(cur.direct == oppo(other.direct) && other.x == x && other.y < y) flag = true;
                else if(sameDist && other.direct == 3 && other.x < x && other.y < y) flag = true;
                else if(sameDist && other.direct == 2 && other.x > x && other.y < y) flag = true;
        }else if(curDirect == 2) {
                if(cur.direct == oppo(other.direct) && other.y == y && other.x < x) flag = true;
                else if(sameDist && other.direct == 1 && other.x < x && other.y > y) flag = true;
                else if(sameDist && other.direct == 0 && other.x < x && other.y < y) flag = true;
        }else if(curDirect == 3) {
                if(cur.direct == oppo(other.direct) && other.y == y && other.x > x) flag = true;
                else if(sameDist && other.direct == 1 && other.x > x && other.y > y) flag = true;
                else if(sameDist && other.direct == 0 && other.x > x && other.y < y) flag = true;
        }// 방향별로 부닥칠 가능성이 있는 조건들 목록이다.
        //cout<<curIdx<<" , "<<otherIdx<<" "<<flag<<endl;
        if(flag) { // 만약 두 원자가 충돌한다면.
                int distance = aabs(cur.x - other.x) + aabs(cur.y - other.y); // 두 원소간 거리이며 x,y 비율과 다르다는 것을 고려해야한다.
                m[distance].push_back(curIdx); // 미리 좌표계에서 나올 수 있는 거리의 차 경우를 세팅해두었기 때문에 해당 거리에 원자 인덱스를 넣어 준비시킨다.
                m[distance].push_back(otherIdx);
        }
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                int answer = 0;
                vector<node> atom;
                scanf(" %d",&n);
                check = vector<bool>(n,false);
                seq = vector<bool>(n,false);
                m = vector<vector<int > >(4100);
                int remove = 0, end = 0;
                for(int i = 0; i < n; i++) {
                        int x, y, direct, k;
                        scanf(" %d %d %d %d",&x,&y,&direct,&k);
                        x += 1000;
                        y += 1000; //음수 양수는 크게 상관이 없음.
                        atom.push_back(node(x,y,direct,k));
                }
                for(int i = 0; i < n; i++) {
                        for(int j = i+1; j < n; j++) {
                                node cur = atom[i], other = atom[j];
                                find(cur,other,i,j);
                        }
                }
                for(auto& candidate : m) { // 원자간 거리가 짧은 쪽부터 순회하는데 이전에 소멸한 원자가 이후에 다른 원자를 소멸시키면 안되기 때문에 이렇게 순서대로 제거한다.
                        if(!candidate.empty()) { // map을 정렬해서 순회가 불가하기 때문에 아예 나올 수 있는 좌표계 거리 벡터를 선언하고 그안에 값을 집어 넣는 방식으로 구현. 즉 서로 거리가 이정도인 원자들의 쌍들을 담고 있다.
                                int len = candidate.size();
                                set<int> tmp; // 만약 아래의 seq if문에서 check or seq를 true로 결정한다면 같은 거리임에도 seq조건문에 걸려 사라지지 않는 문제가 생긴다. 원자가 쌍으로 들어오기 때문에 중복을 제거하기위해 set으로 소멸시킬 원자들을 관리한다,
                                for(int i = 0; i < len; i += 2) {
                                        int a = candidate[i], b = candidate[i+1];
                                        if(!seq[a] && !seq[b]) {// 둘 모두 이전에 제거된 적이 없는 경우에만 제거를 하기위해 seq로 소멸 여부를 결정한다.check랑 역할이 겹치는데 수정하기 귀찮아서 걍 seq로 판단한다.
                                                tmp.insert(a);
                                                tmp.insert(b);
                                        }
                                }
                                for(auto& index : tmp) { // 소멸시킬 원자들을 순회하며 check를 표시해 이보다 큰 거리에서 해당 원자가 나올 경우 소멸시키지 않도록 check or seq애 마킹해둔다.
                                        check[index] = true;
                                        seq[index] = true;
                                }
                        }
                }
                for(int i = 0; i < n; i++) {
                        if(check[i]) { // 소멸된 원자들을 체크홰 값을 구한다.
//                cout<<atom[i].k<<endl;
                                answer += atom[i].k;
                        }
                }
                printf("#%d %d\n",test_case,answer);
                m.clear();
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

//이전엔 한칸한칸 세는 걸로 했는데 이렇게 하면 터진다. 위 방법으로 하면 한칸한칸 이동하는 대신에 충돌 여부를 좌표값의 관계로 파악함으로 시간안에 해결하게 된다.
