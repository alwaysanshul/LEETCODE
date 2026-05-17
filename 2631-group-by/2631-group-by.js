/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let n = this.length
    let ans = {}
    for(let i=0;i<n;i++){
        if(!ans[fn(this[i])])
            ans[fn(this[i])] = []
        ans[fn(this[i])].push(this[i])
    }
    return ans
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */