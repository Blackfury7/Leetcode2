class MovieRentingSystem {
public:
    map<pair<int,int>,int> shops; //{shop,movie}->price
    unordered_map<int,set<pair<int,int>>> unrented; // movie->{{price,shop}...}
    set<vector<int>> rented; // (price,shop,movie)
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto it:entries){
            int shop=it[0];
            int movie=it[1];
            int price=it[2];

            unrented[movie].insert({price,shop});
            shops[{shop,movie}]=price;
        }
    }
    
    vector<int> search(int movie) {
        int n=min(5,(int)unrented[movie].size());
        vector<int> res(n);
        int i=0;
        for(auto it:unrented[movie]){
            if(i>=n) break; 
            res[i]=it.second;
            i++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price=shops[{shop,movie}];
        rented.insert({price,shop,movie});
        unrented[movie].erase({price,shop});
    }
    
    void drop(int shop, int movie) {
        int price=shops[{shop,movie}];
        unrented[movie].insert({price,shop});
        rented.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        int n=min(5,(int)rented.size());
        vector<vector<int>> res(n);
        int i=0;
        for(auto it:rented){
            if(i>=n) break; 
            res[i]={it[1],it[2]};
            i++;
        }
        return res;
    }
};
