class Solution {
public:
    int bestClosingTime(string customers) {
        //penalty for closing at 0th time is number of yesses...after that for each yes encountered, penalty decrease...and each no encountered penalty increases.
        int no = 0, yes = 0;
        for(int i=0;i<customers.size();i++)
        {
            if(customers[i] == 'N')
            {
                no++;
            }
            else
                yes++;
        }
        int pen = yes;
        int minpen = yes;
        int minpos = -1;
        for(int i=0;i<customers.size();i++)
        {
            if(customers[i] == 'Y')
                pen--;
            else
                pen++;
            if(pen<minpen)
            {
                minpos = i;
            }
            minpen = min(minpen,pen);

        }
        return minpos+1;
    }
};