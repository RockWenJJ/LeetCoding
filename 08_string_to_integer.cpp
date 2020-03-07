class Solution {
public:
    void erase_starting_spaces(string &str){
        auto it = str.begin();
        while((*it) == ' ' && it != str.end()){
            str.erase(it);
        }
    }
    
    bool positive(string &str){
        if(str.length() > 0 && str[0]=='-'){
            str.erase(str.begin());
            return false;
        } 
        else if(str.length() > 0 && str[0]=='+'){
            str.erase(str.begin());
            return true;
        } 
        else{
            return true;    
        }
    }
    
    int convert(string &str, bool pos){
        long long res = 0;
        auto it = str.begin();
        if(pos){
            while(it != str.end()){
                if((*it)>='0' && (*it)<='9'){
                    res = res*10 + (*it) - '0';
                    if(res > INT_MAX) return INT_MAX;
                }
                else{
                    return res;
                }
                ++it;
            }
        }
        else{
            while(it != str.end()){
                if((*it)>='0' && (*it)<='9'){
                    res = res*10 - ((*it) - '0');
                    if(res < INT_MIN) return INT_MIN;
                }
                else return res;
                ++it;
            }
        }
        return res;
    }
    
    int myAtoi(string str) {
        erase_starting_spaces(str);
        bool pos = positive(str);
        int result = convert(str, pos);
        return result;
    }
};