```c++
    
    int st = 0, end = 0, cnt = 0, len = 0;
    // [st..end]: rep current window:


    while(end < n) {

        update what is in current window.

        while ( invalid window ) {
            // reduce window size: till it's a valid window
            
            update what is in current window

            st++;
        }

        (here) current window is always valid: so update len or something.

        // increase window size
        end++;
    }

```