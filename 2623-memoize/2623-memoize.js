/**
 * @param {Function} fn
 * @return {Function}
 */

function memoize(fn) {
    const cache = new Map()
    let callCount = 0

    const memoized = function(...args) {
        let key = JSON.stringify(args)
        if(cache.has(key))
            return cache.get(key)
        
        callCount++
        let res = fn(...args)
        cache.set(key, res)
        return res
    }

    memoized.callCount = function() {
        return callCount
    }

    return memoized
}



/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */

//  function memoize_other_way(fn) {
//     let callCount = 0
//     cache = []
    
//     const memoized = function(...args) {
//         for(let i=0;i<cache.length;i++) {
//             let entry = cache[i]
//             if( isSameArgs(entry.args, args)){
//                 return entry.result
//             }
//         }
//         callCount++
//         let res = fn(...args)
//         cache.push({args:[...args],result:res})
//         return res        
//     }   

//     memoized.getCallCount = function() {
//         return callCount
//     }

//     return memoized
// }

// function isSameArgs(arg1, arg2){
//     if(arg1.length !== arg2.length)
//         return false
//     for( let i=0;i<arg1.length;i++){
//         if(arg1[i]!==arg2[i])
//             return false
//     }
//     return true
// }