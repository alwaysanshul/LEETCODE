/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    const no_of_arguments = args.length  
    return  no_of_arguments
};

/**
 * argumentsLength(1, 2, 3); // 3
 */