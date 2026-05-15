/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let n = arr.length
    let ans = []
    
    if(n===0) return ans
    if(size>=n){
        ans.push(arr)
        return ans
    }

    let idx = 0
    for(let i=0;i<Math.floor(n/size);i++) {
        let temp = []
        let j=0
        while(j<size){
            temp.push(arr[idx++])
            j++    
        }
        ans.push(temp)
    }
    if(idx<n){
        let leftover = []
        for(let i=(n-(n%size));i<n;i++){
            leftover.push(arr[idx++])
        }
        ans.push(leftover)
    }
    return ans
};
