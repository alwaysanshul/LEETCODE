var TimeLimitedCache = function () {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function (key, value, duration) {
    const existingEntry = this.cache.get(key);
    if (existingEntry) 
        clearTimeout(existingEntry.timeoutId);
        
    const timeoutId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    this.cache.set(key, { value, timeoutId });

    return !!existingEntry;
};

TimeLimitedCache.prototype.get = function (key) {
    return this.cache.has(key)
        ? this.cache.get(key).value
        : -1;
};

TimeLimitedCache.prototype.count = function () {
    return this.cache.size;
};