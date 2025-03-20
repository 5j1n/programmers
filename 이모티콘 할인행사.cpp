    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int emoticons_num;
    vector<int>sale_rate, emoticon;
    vector<vector<int>>user;
    vector<int> answer;

    void tracking(int size, int idx) {
        if (size == emoticons_num) {
            vector<pair<int, int>>tmp_v(user.size());
            vector<int>prices(sale_rate.size());
            for (int i = 0; i < sale_rate.size(); i++) {
                //cout << sale_rate[i] << " ";
                prices[i] = emoticon[i] * (100 - sale_rate[i]) / 100;

            }
            //cout<<"\n";
            for (int i = 0; i < user.size(); i++) {
                int required_sale = user[i][0];
                int price = 0;
                for (int j = 0; j < sale_rate.size(); j++) {
                    if (required_sale > sale_rate[j]) continue;
                    //cout<<"!";
                    price += prices[j];
                }
                //cout<<price<<"\n";
                if (price >= user[i][1]) {
                    tmp_v[i] = { 1,0 };
                }
                else {
                    tmp_v[i] = { 0,price };
                }
            }
            int plus = 0, sum = 0;
            for (int i = 0; i < tmp_v.size(); i++) {
                if (tmp_v[i].first)plus++;
                else sum += tmp_v[i].second;
            }
            if (answer[0] < plus || (answer[0] == plus && answer[1] < sum)) {
                answer = { plus,sum };
                
            }
            return;
        }

        for (int i = idx; i < emoticon.size(); i++) {
            for (int j = 10; j <= 40; j += 10) {
                sale_rate.push_back(j);
                tracking(size + 1, i + 1);
                sale_rate.pop_back();
            }
        }
        return;
    }
    vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
        emoticon = emoticons;
        user = users;
    
        answer = { 0,0 };
        emoticons_num = emoticons.size();
        tracking(0, 0);
        return answer;
    }
