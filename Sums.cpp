#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); //sorting

    vector<vector<int>> ans; //vector of vectors to store all the triplets
                             //to store a,b,c

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1;
            int high = nums.size() - 1;
            int sum = 0 - nums[i];

            while (low < high)
            {

                if (nums[low] + nums[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]); //inserting triplets
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);

                    while (low + 1 < high && nums[low] == nums[low + 1]) //no duplicate low
                        low++;
                    while (low < high - 1 && nums[high] == nums[high - 1]) //no duplicate high
                        high--;

                    low++;  //brand new low
                    high--; //brand new high
                }
                else if (nums[low] + nums[high] > sum)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> vect;
    int a, n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vect.push_back(a);
    }

    vector<vector<int>> result = threeSum(vect);
    cout << "idk how to print a vector of vectors"
}
