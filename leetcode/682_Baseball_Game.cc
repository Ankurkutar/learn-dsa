#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string>& ops) {
    vector<int>record;

    for(string &op : ops){
        if(op == "+"){
            int size = record.size();
            if (size >= 2) {
                record.push_back(record[size - 1] + record[size - 2]);
            }
        }else if(op == "D"){
            record.push_back(2 * record.back());
        }else if(op == "C"){
            record.pop_back();
        }else{
            record.push_back(stoi(op));
        }

        
    }
    int totalScore = 0;
    for(int score : record){
        totalScore += score;
    }
    return totalScore;
}

int main() {
    vector<string> ops = {"5","2","C","D","+"};
    cout << "Total Score: " << calPoints(ops) << endl;
    return 0;
}