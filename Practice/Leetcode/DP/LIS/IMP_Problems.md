# Largest Divisible Subset
    - bcz "based on the intuition that we need to sort the array", then only we found that "if cur elem is divisible by jth elem: then it's divisible by all prev elems in j's subset"
        - hence, reduced the TC and got intuition for repeating subproblems

# Longest String Chain 
    - "i.e why sorting the array is imp in Subset type problems", Bcz without sorting it brute force doesn't work, bcz for solving dp[i] we need to find it's dependency on the smaller subproblem in between 0...i-1, but something bigger that is a part of a bigger problem might appear in left: 
        - so 1st we sort then solve.

# Number of Longest Increasing Subsequence
