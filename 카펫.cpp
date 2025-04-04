#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = brown + yellow;
    
    for (int i = 1; i<=width/2; i++){
        if (width%i==0){
            int col = i;
            int row = width/i;
            
            if ((row-2)*(col-2)==yellow){
                answer.push_back(row);
                answer.push_back(col);
                break;
            }
        }
    }
    return answer;
}
