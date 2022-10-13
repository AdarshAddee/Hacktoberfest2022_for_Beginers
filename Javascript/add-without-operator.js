var a = prompt('Enter first number');
var b = prompt('Enter second number');

var sum = add(a,b);
function add(a,b)
{
    if (b == 0) {
        return a;
    } else {
        return add(a ^ b, (a & b) << 1)
    }
};

console.log(sum);