// 1912. Design Movie Rental System

class MovieRentingSystem {
public:
    using P = pair<int,int>;
    using T = tuple<int,int,int>;

    unordered_map<int, set<P>> movie_price_shop;      // store unrented 
    set<T> rentedMovies;                              // store rented  price,shop,movie
    map<P, int> priceMap;                             // {shop, movie} -> price

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry: entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            movie_price_shop[movie].insert({price, shop});
            priceMap[{shop, movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        
        for(auto it: movie_price_shop[movie]){
            if(result.size() == 5) break;
            result.push_back(it.second);
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        movie_price_shop[movie].erase({price, shop});
        rentedMovies.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        movie_price_shop[movie].insert({price, shop});
        rentedMovies.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;

        for(auto &it: rentedMovies){
            if(result.size()==5) break;
            auto [_,shop, movie] = it;
            result.push_back({shop, movie});
            
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */