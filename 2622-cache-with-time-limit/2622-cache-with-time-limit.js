var TimeLimitedCache = function() {
    this.cache = new Map()
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let keyExists = this.cache.get(key)
    if(keyExists){
        clearTimeout(keyExists.timeId)
    }
    //Using arrow fn to keep 'this' referring to the Cache instance
    let timeId = setTimeout( ()=>{
        this.cache.delete(key)
    }, duration) 
    this.cache.set(key, {value, timeId})
    return Boolean(keyExists)
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    let keyExists = this.cache.has(key)
    if(keyExists){
        return this.cache.get(key).value
    }
    return -1
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */