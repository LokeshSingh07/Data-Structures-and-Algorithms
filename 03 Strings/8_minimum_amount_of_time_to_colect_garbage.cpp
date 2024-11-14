// 2391. Minimum Amount of Time to Collect Garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int pickP=0, pickG=0, pickM=0;
        int travelP=0, travelG=0, travelM=0;
        int lastP=0, lastG=0, lastM=0;

        for(int i=0; i<n; i++){
            string temp = garbage[i];
            for(char ch: temp){
                if(ch == 'P'){
                    pickP++;
                    lastP = i;
                }
                else if(ch == 'G'){
                    pickG++;
                    lastG = i;
                }
                else{
                    pickM++;
                    lastM = i;
                }
            }
        }

        // find travel time
        for(int i=0; i<lastP; i++){
            travelP += travel[i];
        }
        for(int i=0; i<lastG; i++){
            travelG += travel[i];
        }
        for(int i=0; i<lastM; i++){
            travelM += travel[i];
        }

        return ((pickP + travelP) + (pickG + travelG) + (pickM + travelM));
    }
};