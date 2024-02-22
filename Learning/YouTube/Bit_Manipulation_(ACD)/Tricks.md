
### 1. Find Even/Odd: 
    - `(num & 1 == 1) i.e num is odd`

### 2. unset the LSB: 
    -`(num & (num-1))`

    - eg:   num:        "100100100....10000"
            num-1:      "100100100....01111"
        num & num-1:    "100100100....00000"

### 3. only keep the LSB as set bit: 
    -`(num & ~(num-1))`

    - eg: num: "10101010....100000"

        -> num-1: (all same && LSB to rightmost bit = opposite sign i.e 0111...1)

        -> ~(num-1): (all different && LSB to rightmost bit = same sign i.e 10000...0)

        -> (num & ~(num-1)): (101010...1000 & 010101...1000) => only the LSB is set, rest are unset

### 4. check which bit is set for an integer: 
    `for(b = 0 to b < 32) if(num & (1 << b)) cout << "set bit" << endl;`

### 5. can move 1 to any bit location: `1<<b or 1>>b`, *b: bit location*

### 6. num: make bth bit set->unset, rest all same
    *the positions that are to be kept same Xoring/Oring nums with 0, would keep them same i.e 1^0 = 1, 0^0 = 0*, 
    *from set->unset: make 1 go to bth position && xor it with set i.e 1 of nums, bth bit = 0*
    `solution: (num  ^ (1 << b))`

### 7. similary make the bth bit unset->set, rest all same
    `(num | (1 << b)) OR (num ^ (1 << b))
    (num ^ (1 << b)) is used to toggle ith bit`
    
### 8. Cnt no of set bits: in TC: O(no of set bits)
    - travelling to each LSB and update the number.
    - `int setBitCnt(int num){
        int cnt = 0;
        while(num) {
            num = num & (num-1); // unset the lsb and update num to that num
                // But what about the Complexity of the AND operation ??
            cnt++;
        }
        return cnt;
    }`

### 9. to find xor in range(a,b) i.e a^a+1^a+2....b
    - Use the concept of `prefix-xor` i.e xor of n^n-1^n-2....1
    - xor of a to b = prefix_xor(b)^prefix_xor(a-1)
        - numbers from a-1 to 0 in both gets xored out to 0
    - Property of prefix xor:
        - based on result of (n%4 == 1/2/3/0) we can find the value of prefix_xor(n)
        - `if(n%4 == 0) return n`
        - `if(n%4 == 1) return 1`
        - `if(n%4 == 2) return n+1` // eg: prefXor(2)
        - `if(n%4 === 3) return 0` // eg: prefxor(3)


### 10. Another Way to traverse bits of a number 
    - check the last bit for set/unset => using (num % 2 == 0 -> unset -> unset_cnt++) OR (num & 1 -> set -> set_cnt++).
    - Now right shift the number by 1 pos OR div the num by 2 and update the number to this value.
    - continue the process.

### 11. For every number, may not need to travel to all the 64 bits, optimal way:
    - for(int i = 0; (1 << i) <= num; i++) {
        if(num & (1 << i)) // set bit
        else // unset bit
    }

### 12. Check if number is a power of 2 ?
    - if it's a power of 2: (num & (num-1)) == 0 && it should be > 0.

    - bool checkPowerOfTwo(int n) {
        return (n && !(n & (n-1)))
    } 

### 13. Bitwise AND in a range: O(logN)
    - NOTE: AND operator always reduce the values Or keep it equal. But Never increases it

    - l & l+1,.....r-2 & r-1 & r => r&(r-1) : unset the rightmost set bit.

    - res = r & (r-1) => whatever is the new rightmost set bit: if we AND numbers greater than res with res, new result will always be res.

    - So we ignore those greater numbers and AND the rest of the smaller nmbers left in the range.

    - CODE: while(left < right) {
                right = (right & right-1);
            }
            return right;





































