/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let result = []

    function flattenHelper(currentArray, currentDepth){
        for(let i=0;i<currentArray.length;i++) {
            if(Array.isArray(currentArray[i]) && currentDepth>0)
                flattenHelper(currentArray[i],currentDepth-1)
            else 
                result.push(currentArray[i])
        }
    }
    flattenHelper(arr,n)
    return result
};