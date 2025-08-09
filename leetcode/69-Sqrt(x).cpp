// Common mistakes: ignoring integer overflow 

// Approach: Binary search to find the square root of x
// This approach runs in O(log x) time complexity and uses O(1) space.

class Solution {
public:
    float morePrecision(int ans, int square)
{
    float an = ans;
    float sq = square;
    float y;
    for(float i=ans; i<=i+1; i += 0.01 )
    {
        if(i*i <= sq)
        {
            y=i;
        }
        else
        {
            break;
        }
    }
    return y;
}

float mySqrt(int x) {
        if (x==0) return 0;
        if(x==1) return 1;

        int s=0, e=x, m=s+(e-s)/2;

        while(s<=e)
        {
            if(m == x/m) return m;
            else if(m < x/m && (m+1) > x/(m+1))
            {
                return morePrecision(m, x);
            }
            else if(m < x/m) 
            {
                s = m+1;
                m=s+(e-s)/2;
            }
            else if(m > x/m)
            {
                e = m-1;
                m = s+(e-s)/2;
            }
        }
        return -1;
    }

};