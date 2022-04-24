class UndergroundSystem {
public:
    map<int,pair<string,int>> mp;
    map<pair<string,string>,vector<int>> hsh;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]={stationName,t};
    }
    void checkOut(int id, string stationName, int t) {
        auto it=mp[id];
        hsh[{it.first,stationName}].push_back(t-it.second);
    }
    double getAverageTime(string startStation, string endStation) {
        int sum=0;
        double div=hsh[{startStation,endStation}].size();
        for(auto &it:hsh[{startStation,endStation}]){
            sum+=it;
        }
        double ans=sum/div;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */