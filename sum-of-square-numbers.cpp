class Solution {
public:
    bool judgeSquareSum(int c)
{
    int l = 0, r = sqrt(c);
    while(l <= r){
        double multiply = (double)l * l + (double)r * r;
        if(multiply == c)
            return true;
        else if(multiply < c)
            l++;
        else
            r--;
    }
    return false;
}
};