using namespace std;
class Solution
{
    public:
    int maxTurbulenceSize(vector<int> &arr){

        int n = arr.size();
        int ans = 1;
        int start = 0;
        int end = 0;
        while (end < n - 1)
        {
            if (start == end)
            {
                if (arr[start] == arr[start + 1])
                    start++;
                end++;
            }
            else
            {
                if (arr[end] > arr[end + 1] && arr[end] > arr[end - 1])
                    end++;
                else if (arr[end] < arr[end + 1] && arr[end] < arr[end - 1])
                    end++;
                else
                    start = end;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};