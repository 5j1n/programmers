#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct work {
    int num;
    int start;
    int length;
};

vector<work>wait_queue;
work hdd;

bool cmp(work a, work b) {
    if (a.length == b.length) {
        if (a.start == b.start) {
            return a.num < b.num;
        }
        return a.start < b.start;
    }
    return a.length < b.length;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int rest = jobs.size();
    bool flag = false;
    hdd.num = -1;
    hdd.length = -1;
    while (rest) {
        if (hdd.length == time) {
            answer += hdd.length - hdd.start;
            hdd.num = -1;
        }
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] == time) {
                work tmp;
                tmp.num = i;
                tmp.start = time;
                tmp.length = jobs[i][1];
                wait_queue.push_back(tmp);
                rest--;
            }
        }
        sort(wait_queue.begin(), wait_queue.end(), cmp);
        if (hdd.num == -1 && wait_queue.size() > 0) {
            hdd.num = wait_queue[0].num;
            hdd.start = wait_queue[0].start;
            hdd.length = time + wait_queue[0].length;
            wait_queue.erase(wait_queue.begin());
        }
        time++;
    }
    while (!wait_queue.empty()) {
        if (hdd.length == time) {
            answer += hdd.length - hdd.start;
            hdd.num = -1;
        }
        if (hdd.num == -1 && wait_queue.size() > 0) {
            hdd.num = wait_queue[0].num;
            hdd.start = wait_queue[0].start;
            hdd.length = time + wait_queue[0].length;
            wait_queue.erase(wait_queue.begin());
        }
        time++;
    }
    if (hdd.num!=-1){
        answer += hdd.length - hdd.start;
    }
    return answer / jobs.size();
}
