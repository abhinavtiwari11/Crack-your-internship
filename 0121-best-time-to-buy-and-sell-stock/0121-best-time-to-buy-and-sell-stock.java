class Solution {
    public int maxProfit(int[] prices) {
        
     int first=0;
      int move=0;
      if(prices.length>1){
           move=1;
      }
      else{
          return 0;
      }
int dif=0;
int maxdif=0;
while(move<=prices.length-1){
    if(prices[first]>=prices[move]){
        first = move;
        // first++;
        move++;
    }

    else if(prices[first]<prices[move]){
        
        dif=prices[move]-prices[first];
        if(maxdif<dif){
            maxdif=dif;
        }
        move++;
    }
}

return maxdif;
    }
}