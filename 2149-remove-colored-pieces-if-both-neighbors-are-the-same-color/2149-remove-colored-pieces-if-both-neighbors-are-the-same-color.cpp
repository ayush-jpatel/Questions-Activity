class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A')
            {
                a++;
            }
            else if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B')
            {
                a--;
            }
        }
        
        return (a>0);
    }
};
