class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if((sx==fx && sy==fy))
        {
            if(t==0 || t>1) return true;
            return false;
        }
        if(abs(fx-sx)<=t && abs(fy-sy)<=t) return true;
        return false;
        
    }
};