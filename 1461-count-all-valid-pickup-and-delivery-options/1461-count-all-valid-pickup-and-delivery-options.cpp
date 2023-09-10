class Solution {
public:
    int recurse(int n)
    {
        if(n == 1)
            return 1;
        return n*(2*n-1)*countOrders(n-1);
    }
    int dynamic(int n)
    {
        vector<long long int> vec(n+1);
        vec[0] = 0;
        vec[1] = 1;
        for(int i=2;i<=n;i++)
        {
            vec[i] = (i*(2*i-1)*(vec[i-1]%1000000007))%1000000007;
            // vec[i] = (i*(2*i-1)*)vec[i-1])%1000000007;
        }
        return vec[n];
    }
    int countOrders(int n) {
        // return recurse(n);
        return dynamic(n);
    }
};