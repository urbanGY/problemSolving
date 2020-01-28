#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int width = 0, height = 0;
    brown += 4;
    height = 3;
    while(true){
        width = (brown - height*2)/2;
        if(height<=width){
            int inner_width = width-2, inner_height = height-2;
            if(red == (inner_width*inner_height)){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }else break;
        height++;
    }
    return answer;
}
