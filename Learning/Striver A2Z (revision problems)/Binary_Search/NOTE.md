1. ceil of a number is:
``` c++
    ceil(nums[i]/x) == (nums[i] + x - 1)/x
```

2. when to use BS on answers:
    a. minimizing(maxima) OR maximizing(minima).
    b. types:
        - sweeping
        - atomic item contribution
        - 2d variation

3. One problem with BS on ans: is how can I be sure that "last/smallest/largest mid value which gives check(mid) == 1 is a valid answer or not.

    - make sure you determine that after thinking about every solution.


4. BS on ans: min(max) OR max(min)
    - final answer for the question is the whole thing i.e min(max) Or max(min).
    - and final answer is in between lo and hi.
    - so `determine lo by thinking` about `min` value of `min(max) or max(min)` and vv for hi.