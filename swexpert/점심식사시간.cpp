#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
        int x, y, length;
        Node(int x, int y, int length)
                : x(x), y(y), length(length){
        }
};

struct cmp {
        bool operator()(pair<bool,int> a, pair<bool,int> b) {
                return a.second > b.second;
        }
};
int aabs(int a) {
        return a > 0 ? a : -a;
}
int getDistance(Node people, Node stair) {
        return aabs(people.x - stair.x) + aabs(people.y - stair.y);
}
int n, answer;
vector<vector<int> > board;
bool flag = true;
void find(int num, vector<Node>& choice, vector<Node>& stair) {
        if(num == choice.size()) {
                priority_queue<pair<bool,int>, vector<pair<bool,int> >, cmp> s0,s1;
                queue<int> q0,q1;
                for(auto c : choice) {
                        if(c.length == 0) s0.push({false,getDistance(c,stair[0])});
                        if(c.length == 1) s1.push({false,getDistance(c,stair[1])});
                }

                int time = 0;
                while(true) {
                        time++;
                        //         cout<<"time : "<<time<<" ";
                        while(true) {
                                if(!q0.empty() && q0.front() <= time) q0.pop();
                                else break;
                                //             cout<<"q0"<<" ";
                        }
                        while(true) {
                                if(!q1.empty() && q1.front() <= time) q1.pop();
                                else break;
                                //               cout<<"q1"<<" ";
                        }
                        if(q0.empty() && q1.empty() && s0.empty() && s1.empty() ) break;
                        while(true) {
                                if(!s0.empty() && s0.top().second <= time && q0.size() < 3) {
                                        q0.push(time + stair[0].length);
                                        s0.pop();
                                }
                                else break;
                                //              cout<<"s0"<<" ";
                        }
                        while(true) {
                                if(!s1.empty() && s1.top().second <= time && q1.size() < 3) {
                                        q1.push(time + stair[1].length);
                                        s1.pop();
                                }
                                else break;
                                //            cout<<"s1"<<" ";
                        }
                        //      cout<<endl;
                }

                if(time < answer) answer = time;
                return;
        }
        for(int i = 0; i < 2; i++) {
                choice[num].length = i;
                find(num+1,choice,stair);
        }
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                scanf(" %d",&n);
                answer = 987654321;
                board = vector<vector<int> >(n,vector<int>(n,0));
                vector<Node> choice;
                vector<Node> stair;
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                scanf(" %d", &board[i][j]);
                                if(board[i][j] == 1) choice.push_back(Node(i,j,board[i][j]));
                                if(board[i][j] > 1) stair.push_back(Node(i,j,board[i][j]));
                        }
                }
                find(0, choice, stair);
                printf("#%d %d\n",test_case,answer+1);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
