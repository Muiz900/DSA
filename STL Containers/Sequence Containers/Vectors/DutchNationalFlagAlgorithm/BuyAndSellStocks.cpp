#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector <int> &arr)
{
    int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : arr) {
            // update minPrice if we find a new lower price
            if (price < minPrice) {
                minPrice = price;
            } 
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
}
int maxProfit2(vector <int> &prices)
{
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i+1] > prices[i]) {
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }

int main(){
    
}