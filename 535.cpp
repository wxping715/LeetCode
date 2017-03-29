class Solution {
public:

    static char letters[26];
    const static int CODE_LENGTH = 6;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (!url2code.count(longUrl)) {
            string code = genCode();
            if (!code2url.count(code)) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return "http://tinyurl.com/"+ url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code2url[shortUrl.substr(shortUrl.length()-CODE_LENGTH)];
    }
    
    
private:

    string genCode() {
        string code = "";
        for (int i = 0; i < CODE_LENGTH; i++)
            code.push_back(letters[rand()%26]);
        return code;
    }

    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
};

char Solution::letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
