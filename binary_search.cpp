#include <iostream>
#include <vector>
using namespace std;
int binsearch (vector<int>&nums,int lb,int ub,int target);
int main ()
{
    vector <int> num = {5,7,7,8,8,10};
    int ans = binsearch (num, 0, num.size() - 1, 8);
    cout << ans;
}
int binsearch (vector<int>&nums,int lb,int ub,int target)
    {
        int mid;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                ub = mid - 1;
            else if (nums[mid] < target)
                lb = mid + 1;
        }
        return -1;
    }