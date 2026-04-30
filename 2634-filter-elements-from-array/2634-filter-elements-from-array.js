/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const n = arr.length
    let filteredArr = []
    for(let i=0;i<n;i++){
        if(fn(arr[i],i))
            filteredArr.push(arr[i])
    }
    return filteredArr
};