### "More State related points to keep in mind":

    1. Always completely follow the state.

    2. If in the nested for loops: a state doesn't make sense i.e according to your State Definition: an answer to this state is impossible then fill it with a default value that won't make sense.

    3. Final Subproblem: that follows the definition of State && that is possible i.e it make sense from State definition (AND not some ideal state of some other problem)
    
        - IMP: i.e Just After State Definition: you must verify the Final Subproblem Or what the question asks can be solved by this State or not. Then only move to Transition.