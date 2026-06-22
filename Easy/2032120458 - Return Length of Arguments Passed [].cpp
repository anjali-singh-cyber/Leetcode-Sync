

// =========================
// Method 1 (javascript)
// =========================

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
     var args_on_even_position = 0, args_on_odd_position = 0;
    for (let i = 0; i < args.length; i++)
    {
        let parity = i % 2;
        if (parity == 0) 
        {
            args_on_even_position = args_on_even_position + 1;
        }
        else
        {
            args_on_odd_position = args_on_odd_position + 1;
        }
    }
    var answer = args_on_even_position + args_on_odd_position;
    return answer;
    
};

/**
 * argumentsLength(1, 2, 3); // 3
 */