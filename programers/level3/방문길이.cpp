#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int solution(string dirs) {
	int answer = 0;
    map<pair<pair<int, int>, pair<int, int> >,bool> m;
    int x = 5 , y = 5;
    for(const auto& c : dirs){
        if(c == 'U' && x-1 >= 0){
            pair<pair<int, int>, pair<int, int> > pr = make_pair(make_pair(x,y),make_pair(x-1,y));
            m[pr] = true;
            pr = make_pair(make_pair(x-1,y),make_pair(x,y));
            m[pr] = true;
            x--;
        }else if(c == 'D' && x+1 <= 10){
            pair<pair<int, int>, pair<int, int> > pr = make_pair(make_pair(x,y),make_pair(x+1,y));
            m[pr] = true;
            pr = make_pair(make_pair(x+1,y),make_pair(x,y));
            m[pr] = true;
            x++;
        }else if(c == 'L' && y-1 >= 0){
            pair<pair<int, int>, pair<int, int> > pr = make_pair(make_pair(x,y),make_pair(x,y-1));
            m[pr] = true;
            pr = make_pair(make_pair(x,y-1),make_pair(x,y));
            m[pr] = true;
            y--;
        }else if(c == 'R' && y+1 <= 10){
            pair<pair<int, int>, pair<int, int> > pr = make_pair(make_pair(x,y),make_pair(x,y+1));
            m[pr] = true;
            pr = make_pair(make_pair(x,y+1),make_pair(x,y));
            m[pr] = true;
            y++;
        }
    }

	return m.size()/2;
}
