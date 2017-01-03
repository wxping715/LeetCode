/*The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.*/



// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution(): buffCnt(0), buffPtr(0) {
        
    }
    
    int read(char *buf, int n) {
        int cnt = 0;
        while (cnt < n) {
            if (buffPtr == 0)
                buffCnt = read4(buff);
            if (buffCnt == 0) break;
            while (cnt < n && buffPtr < buffCnt)
                buf[cnt++] = buff[buffPtr++];
            if (buffPtr == buffCnt)
                buffPtr = 0;
        }
        return cnt;
    }
    
private:
    int buffPtr;
    int buffCnt;
    char buff[5];
};
