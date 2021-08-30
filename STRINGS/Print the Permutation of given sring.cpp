//Problem : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

//Reference : Using bit manipulation [https://www.techiedelight.com/generate-power-set-given-set/]

//Code :
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
void findPowerSet(vector<int> const &S, int n)
{
    // `N` stores the total number of subsets
    int N = pow(2, n);
 
    // generate each subset one by one
    for (int i = 0; i < N; i++)
    {
        // check every bit of `i`
        for (int j = 0; j < n; j++)
        {
            // if j'th bit of `i` is set, print `S[j]`
            if (i & (1 << j)) {
                cout << S[j] << " ";
            }
        }
        cout << endl;
    }
}
 
int main()
{
    vector<int> S = { 1, 2, 3 };
    int n = S.size();
 
    findPowerSet(S, n);
 
    return 0;
}