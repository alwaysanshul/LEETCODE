class OrderedStream                 {
public:
    vector<string> v_str;
    int i = 0;
    
    OrderedStream(int n) {
        v_str.assign(n,"null");
    }
    
    vector<string> insert(int idKey, string value) {
        v_str[idKey-1] = value;
        vector<string> takeout;
        while(i<v_str.size()     && v_str[i]!="null") {
            takeout.push_back(v_str[i]);
            i++;
        }
        return takeout;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */