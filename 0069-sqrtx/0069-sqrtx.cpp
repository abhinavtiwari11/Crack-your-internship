class Solution {
public:
     long long  int mySqrt(int x) {


int s = 0;
int e = x;
long long int ans = 0;
long long int mid = s + (e-s)/2;

while(s<=e){

long long int square = mid*mid;

if(square == x){

return mid;


}



else if(square<long(x)){

ans = mid;

s = mid+1;

}

else{
e = mid-1;

}

 mid = s + (e-s)/2;



}


return ans;

         }
};