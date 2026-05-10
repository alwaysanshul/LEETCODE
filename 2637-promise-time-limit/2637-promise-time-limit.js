/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    async function timeLimited(...args) {
        const promise1 = new Promise((resolve, reject) => {
            const timeId = setTimeout( () => {
                reject("Time Limit Exceeded")
            }, t)
            fn(...args)
                .then((result) => {
                    clearTimeout(timeId)
                    resolve(result)
                })
                    .catch((err) => {
                        clearTimeout(timeId)
                        reject(err)                       
                    })
        })

        return promise1
    }

    return timeLimited;
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */