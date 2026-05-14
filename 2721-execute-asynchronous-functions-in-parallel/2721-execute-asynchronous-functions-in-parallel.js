/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
        let p = new Promise((resolve, reject)=>{
            let resolveCount=0
            let results = new Array(functions.length)
            
            if(functions.length==0)
                resolve([])

            for(let i=0;i<functions.length;i++) {
                functions[i]()
                    .then((result)=>{
                        results[i] = result

                        resolveCount++
                        if(resolveCount==functions.length){
                            resolve(results)
                        }
                    })
                        .catch((err)=>{
                            reject(err)
                        })
                    
            }
        })
        return p
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */