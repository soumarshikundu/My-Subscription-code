

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void f(int index,float weeklyBudget,float current_cost,vector<pair<string,float>>&newspaperPrices,vector<string>&collectAry,vector<vector<string>>&ansAry){
    if(index==newspaperPrices.size()){
        if(current_cost<=weeklyBudget){
            ansAry.push_back(collectAry);
            return;
        }
        return;
    }
    if(current_cost+newspaperPrices[index].second<=weeklyBudget){
        collectAry.push_back(newspaperPrices[index].first);
        f(index+1,weeklyBudget,current_cost+newspaperPrices[index].second,newspaperPrices,collectAry,ansAry);
        collectAry.pop_back();
    }
    f(index+1,weeklyBudget,current_cost,newspaperPrices,collectAry,ansAry);
    return;
}
int main()
{
    float weeklyBudget;
    cin>>weeklyBudget;
    vector<pair<string,float>>newspaperPrices;
    newspaperPrices.push_back({"TOI",26});
    newspaperPrices.push_back({"Hindu",20.5});
    newspaperPrices.push_back({"ET",34});
    newspaperPrices.push_back({"BM",10.5});
    newspaperPrices.push_back({"HT",18});
    vector<vector<string>>ansAry;
    vector<string>collectAry;
    f(0,weeklyBudget,0,newspaperPrices,collectAry,ansAry);
    for(int i=0;i<ansAry.size();i++){
        if(ansAry[i].size()>1){
        for(int j=0;j<ansAry[i].size();j++){
            
            cout<<ansAry[i][j]<<" ";
        }
        cout<<endl;
        }
    }

    return 0;
}
