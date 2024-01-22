**APPROACH to solve any DP problem**

    - FLOW: State > Transition > Flow of States > BC & finalSubproblem (depends of state definition)

    - Imagine the brute force approach in your mind.

    - If it seems Greedy -> see for cases when it can go greedily wrong, and if we're to explore all the ways   

    - See if there is a subproblem you're repeatedly solving
        - How did you define that subproblem ? -> define a state based on it

            - ONLY WORK ON THE ith STATE -> i.e explore all possible stuffs you can do on the ith STATE && Nothing ELSE, and make the transition equation to depend on the smaller states.

    - Based on the brute force appraoch: find the TRANSITION, i.e subproblems on which the state depends

    - Based on the Transition, determine flow of states i.e which dp cells to fill first to solve the ith state.

    - BC(Base Case): Solution of the Smallest State which could be trivially solved + THINK about OUT OF BOUND CASES.

**TIME COMPLEXITY:**

    -  (# states) * avg transition time of each state

    - OR (total transition time)

**GOOD PROBLEMS**

    1. Know why is the code for Coin_Combination 1 and 2 different.
    2. Couldn't solve in one go :

        - Array Description (=> good dp state) => "V.V.IMP STANDARD solution given by Priyansh"

        - Counting Towers (=> good problem,how'd the ith problem look like, based on that we solve it, keep in mind to only solve the ith ind)

        - Rectangle Cutting (=> for a particular rectangle: what all can we do to reduce the problem ?)

        - Printing Based > Money Sum

        - Game Dp > Removal Game

        - LONGEST INCREASING SUBSEQUENCE > bcz of Constraints



