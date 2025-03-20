#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> delivery, pickup;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int now = cap;
    long long answer = 0;
    int rest = 0;
    for (int i = 0; i<deliveries.size(); i++)
    {
        rest += deliveries[i];
        if (deliveries[i]) delivery.push_back({deliveries[i],i});
    }
    for (int i = 0; i<pickups.size(); i++)
    {
        if (pickups[i]) pickup.push_back({pickups[i],i});
        rest +=pickups[i];
    }
    
    while(rest>0){
        now = cap;
        int dist = 0;
        int size = delivery.size();
        //cout<<"배달 할 곳 개수: "<<size<<"\n";
        for (int i = size-1; i>-1; i--){
            if (now>0){
                dist = max(dist,delivery[i].second+1);
                int load = min(delivery[i].first,now);
                now -= load;
                delivery[i].first -= load;
                rest -=load;
                if (!delivery[i].first) delivery.pop_back();
            }
            if (!now) break;
        }
        now = cap;
        size = pickup.size();
        //cout<<"픽업 할 곳 개수: "<<size<<"\n";
        for (int i = size-1; i>-1; i--){
            if (now>0){
                dist = max(dist,pickup[i].second+1);
                int load = min(pickup[i].first,now);
                now -= load;
                pickup[i].first -= load;
                rest-=load;
                if (!pickup[i].first) pickup.pop_back();
            }
            if (!now) break;
        }
        answer+=dist*2;
    }
    return answer;
}
