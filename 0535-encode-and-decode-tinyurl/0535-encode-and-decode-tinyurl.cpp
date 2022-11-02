class Solution {
public:
    string str;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        str = longUrl;
        // Please don't judge my encoding algo, im just a beginner :(
        for(int i=0;i<str.length();i++) {
            str.at(i) = str.at(i) + 1;
        }
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        str = shortUrl;
        for(int i=0;i<str.length();i++) {
            str.at(i) = str.at(i) - 1;
        }
        return str;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));