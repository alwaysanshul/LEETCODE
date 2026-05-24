/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let isCalled=false
    let timeId=null
    return function(...args) {
        if(isCalled){
            clearTimeout(timeId)
            isCalled=false
        }
        timeId = setTimeout(()=>{
            fn(...args)
            isCalled=false
        },t)
        isCalled=true
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */