class Solution {
public:
    string digit(int num){
        // if(num == 0)    return "Zero ";
        if(num == 1)    return "One ";
        if(num == 2)    return "Two ";
        if(num == 3)    return "Three ";
        if(num == 4)    return "Four ";
        if(num == 5)    return "Five ";
        if(num == 6)    return "Six ";
        if(num == 7)    return "Seven ";
        if(num == 8)    return "Eight ";
        if(num == 9)    return "Nine ";
        else            return "";
    }
    string teen(int num){
        if(num == 0)  return "Ten ";
        if(num == 1)  return "Eleven ";
        if(num == 2)  return "Twelve ";
        if(num == 3)  return "Thirteen ";
        if(num == 4)  return "Fourteen ";
        if(num == 5)  return "Fifteen ";
        if(num == 6)  return "Sixteen ";
        if(num == 7)  return "Seventeen ";
        if(num == 8)  return "Eighteen ";
        if(num == 9)  return "Nineteen ";
        else          return "Teen ";
    }
    string tens(int num){
        if(num == 2)    return "Twenty ";
        if(num == 3)    return "Thirty ";
        if(num == 4)    return "Forty ";
        if(num == 5)    return "Fifty ";
        if(num == 6)    return "Sixty ";
        if(num == 7)    return "Seventy ";
        if(num == 8)    return "Eighty ";
        if(num == 9)    return "Ninety ";
        else return "";
        // if(num == 0 || num == 1)    return "Tens ";
    }
    string giveNum(string num){
        string res = "";
        // if(num < 10){
        if(num.size() == 1){
            res += digit(num[0] - '0');
            // return res;
        }
        // else if(num < 100){
        else if(num.size() == 2 || (num[2] == '0')){
            if(num[1] == '1'){
                res += teen(num[0] - '0');
                // res += teen(num/10);
            }
            else{
                res += tens(num[1]-'0');
                res += digit(num[0]-'0');
                // res += tens(num/10);
                // res += digit(num%10);
            }
            // return res;
        }
        else{
            // if(num%10){
            // cout << num << ' ';
            if(num[2]-'0'){
                res += digit(num[2]-'0');
                // res += digit(num%10);
                res += "Hundred ";
            }
            string s = "";
            s.push_back(num[0]);
            s.push_back(num[1]);
            // cout << "s-> " << s << endl;
            res += giveNum(s);
        }
        return res;
    }
    string numberToWords(int num) {
        string res = "";
        int count = 0;
        string part = "";
        if(!num)
            return "Zero";
        while(num){
            int temp = num%10;
            num/=10;
            count++;
            part.push_back(temp + '0');
            string str = "";
            if( num == 0 || count%3 == 0){
                // cout << part << ' ';
                str = giveNum(part);
                part = "";
                if(str.size() < 2){
                    continue;
                }
                if(count > 9)
                    str += "Billion ";
                else if(count > 6)
                    str += "Million ";
                else if(count > 3)
                    str += "Thousand ";
                res = str + res;
            }
            
        }
        while(res.size() && res.back() == ' ')
            res.pop_back();
        return res;
    }
};