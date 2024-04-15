### 1. How to identify whether to apply form 1 or form 2 ?? 
<br>

**Step1)** Apply Form 1 on a problem i.e (inc window size till it's invalid, then dec window size till it's valid && between both the process record possible solution.)
<br>

**Step 2)** if there could be a case when dec window size (i.e si++, with a fixed ei), you might miss out on a lot of possible solutions then we apply form 2.
<br> 

**eg:** [subarray with k different integers](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

    - [1,2,1,2,3], k = 2. If we apply form 1 => 1st invalid window occurs is [1,2,1,2,3] cnt = 3 i.e [1,2], [1,2,1], [1,2,1,2], and we decrease it to make it valid [2,3]. now cnt = 4. But we miss out on subarrays like [2,1], [2,1,2], [1,2]

**FORM 2** *i.e modifying the problem statement*

**Step 1)** #subarrays with exactly k integers = #subarrays with <= k integers - #subarrays with <= (k-1) integers.

**Step 2)** using FORM 1, we can find #subarrays with <= k integers