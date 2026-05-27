/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    let result = (Array.isArray(obj))?[]:{}

    for(let key in obj){
        let value = obj[key]
        if(value){
            if(typeof value === 'object'){
                value = compactObject(value)
            }
            (Array.isArray(obj))?result.push(value):(result[key] = value)
        }
    }
    return result
};