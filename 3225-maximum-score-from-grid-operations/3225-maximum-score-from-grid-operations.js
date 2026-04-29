/**
 * @param {number[][]} grid
 * @return {number}
 */

let prefix = []   // prefix sums
let grid = []     // input grid
let n = 0         // size n
let dp = []       // memo table

var maximumScore = function(grid_) {
    grid = grid_
    n = grid.length

    prefix = Array.from({ length: n + 1 }, () =>
        new Array(n + 1).fill(0)
    );

    for(let j=0;j<n;j++) {  // column loop
        for(let i=1;i<=n;i++) {  // row loop
            prefix[i][j+1] = prefix[i-1][j+1] + grid[i-1][j];
        }
    }

    dp = Array.from({ length: 2 }, () =>
        Array.from({ length: n + 1 }, () =>
            new Array(n + 1).fill(-1) 
        )
    )   
    return helper(0,0,1) // recursion
};

var helper = function(prevTrue, prevLen, col) {
        
    if(col==n+1)  // base case
        return 0;

    if(dp[prevTrue][prevLen][col]!=-1)  
        return dp[prevTrue][prevLen][col]

    let res = 0;

    for(let len=0;len<=n;len++) {
        let prevAns=0, currAns=0;

        if(prevTrue==0 && col>1 && len>prevLen)
            prevAns = prefix[len][col-1] - prefix[prevLen][col-1];

        if(prevLen > len) 
            currAns  = prefix[prevLen][col] - prefix[len][col];
        
        let res1 = currAns + prevAns + helper(1, len, col+1)
        let res2 = prevAns + helper(0, len, col+1)

        res = Math.max(res, Math.max(res1,res2));
    }
    return dp[prevTrue][prevLen][col] = res;
}