class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0,tcost=0;
        for(int i=0;i<gas.size();i++){
            tgas+=gas[i];
            tcost+=cost[i];
        }
        if(tgas<tcost) return -1;

        int start=0,total=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                start=i+1;
            }
        }
        return start;
    }
};