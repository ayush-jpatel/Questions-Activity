class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // return t>=max(abs(sx-fx),abs(sy-fy));
        int x= max(abs(sx-fx),abs(sy-fy));
        if(x == 0){
            if(t == 1)
                return false;
            return true;
        }
        if(x<=t)
            return true;
        return false;
    }
};


// while(sx!=fx && sy!=fy)
//         {
//             if(sx > fx)
//                 sx--;
//             else if(sx < fx)
//                 sx++;
//             if(sy > fy)
//                 sy--;
//             else if(sy < fy)
//                 sy++;
//             t--;
//         }
//         return (t>=0);