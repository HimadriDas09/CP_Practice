- Any Number can be represented in any kind of representation.
    eg: binary, ternary, decimal, ...

- Every Binary Numnber can be expressed as 
    Sum (bi * (2^i))

- Righmost bit is LSB which holds some value i.e righmost bit that is set

- NOTE: num = 100000 -> then what is the binary rep of num - 1 
    -> how does it fill: 1st it fills in for smaller indices: once all the indices are filled i.e 0...i all bits are set
        - then in the next number: we set the i+1th bit && 0...i = unset

- # Find Even/Odd: `(num & 1 == 1) i.e num is odd`
- # unset the LSB: `(num & (num-1))`
- # only keep the LSB as set bit: `(num & ~(num-1))`
- # check which bit is set for an integer: 
    `for(b = 0 to b < 32) if(num & (1 << b)) cout << "set bit" << endl;`
- # can move 1 to any bit location: `1<<b or 1>>b`, b: bit location
- # num: make bth bit set->unset, rest all same
    *the positions that are to be kept same Xoring/Oring nums with 0, would keep them same i.e 1^0 = 1, 0^0 = 0*, 
    *from set->unset: make 1 go to bth position && xor it with set i.e 1 of nums, bth bit = 0*
    `solution: (num  ^ (1 << b))`
- # similary make the bth bit unset->set, rest all same
    `(num | (1 << b)) OR (num ^ (1 << b))`
    


*-------------------------------------------------------------------------*

# operations 
    - AND, OR, XOR, Left and right shift
    - AND   -> any one unset bit -> AND of bits = 0
            -> all set bits -> AND of bits = 0
    - OR -> if any one bit is set -> OR of bits = set i.e 1
        else -> OR of bits = unset i.e 0

    - XOR (betn 2 nos) -> if only 1 set bit -> result = set
          -> else i.e both bits set/ both unset -> result = unset  
          -> NOTE: exactly like OR: but 1^1 = 0, whereas 1|1 = 1

    - Left Shift: -> left shifting a number by x bits:
            = all the bits are shifted by x units to the left: so the places from where it is shifted are filled with 0s.
            = ith bit now represent bi*(2^(i+x)) i.e bi*(2^x.2^i)
            = so taking 2^x out of all the bits
            = we get a result of (original sum * 2^x)

    - Right shift:
        - right shifting by x units: eq to (original_num / 2^x)

/*----------------------------------------------------------------------*/

# NOTE: rather than mul or div by powers of 2:
    prefer <<, >> by x units: to do Num * 2^x OR Num / 2^x

# TRICKS:

    1. Check if a num is even or odd
        - (num & 1) == 1 -> ODD

            - 0th bits: 0/1 : if(0 & 1 == 0) && if(1 & 1 == 1) 
                - if(num & 1) == 0: num is odd, else even.
            - other bits: 0/1 doesn't matter => & with 0 = 0
    
    2. binaryString(num) = "10001000....100100"
        -> unset the LSB bit: i.e bit holding the least value of the binary rep: i.e rightmost set bit of the binary rep 

        -> Approach: 
            -> "suppose 0...i-1 th bit = unset, then ith bit = set and this bit only we're supposed to unset"

            -> WHAT IS THE BINARY REP OF num-1 ??
                -> if in num: 0...i-1 = unset and ith = set
                -> then in num-1: 0...i-1 = set and ith = unset

                eg: 7: 111 and 8: 1000


            num:        "100100100....10000"
            num-1:      "100100100....01111"
        num & num-1:    "100100100....00000"

        -> DOING (num & num-1): would make all the bits 0 from the LSB to the rightmost bit of the binary rep

    3. Similary what'd (num & ~(num-1)) do ??

        -> eg: num: "10101010....100000"

        -> num-1: (all same && LSB to rightmost bit = opposite sign i.e 0111...1)

        -> ~(num-1): (all different && LSB to rightmost bit = same sign i.e 10000...0)

        -> (num & ~(num-1)): (101010...1000 & 010101...1000) => only the LSB is set, rest are unset