// Github username: bhautikposhiya
// Aim: Single number
// Date:18/10/2022


/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = (nums) => {
    let res = 0;

    nums.forEach(num => { res ^= num; });

    return res;
};